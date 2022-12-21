#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"
#include <fstream>
#include <filesystem>
#define cameraPage 0
#define payPage 1
namespace fs = std::filesystem;

licensePlateDialog::licensePlateDialog(QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::licensePlateDialog), _resultStr("")
{
  ui->setupUi(this);

  _camera = new QCamera(this);
  _cameraViewFinder = new QCameraViewfinder(this);
  _layout = new QVBoxLayout;

  _camera->setViewfinder(_cameraViewFinder);
  _layout->addWidget(_cameraViewFinder);
  _layout->setMargin(0);
  ui->m_camArea->setLayout(_layout);
  ui->stackedWidget->setCurrentIndex(cameraPage);

  // Capture image from camera
  _imageCapture = new QCameraImageCapture(_camera);
  connect(_imageCapture,
          &QCameraImageCapture::imageCaptured,
          this,
          &licensePlateDialog::ProcessCapturedImage);
  connect(ui->m_btnStart,
          &QPushButton::clicked,
          this,
          &licensePlateDialog::StartCamera);
  connect(ui->m_btnStop,
          &QPushButton::clicked,
          this,
          &licensePlateDialog::StopCamera);
  connect(ui->m_btnCapture,
          &QPushButton::clicked,
          this,
          &licensePlateDialog::CaptureImage);
  connect(ui->m_btnBack,
          &QPushButton::clicked,
          this,
          &licensePlateDialog::backSpaceforTXT);
  connect(ui->m_btnClear,
          &QPushButton::clicked,
          this,
          &licensePlateDialog::clearTXT);

  for (auto& btn : ui->m_buttons)
    {
      connect(btn,
              &QPushButton::clicked,
              this,
              &licensePlateDialog::PaymentBtnClicked);
    }

  _cur_path = fs::current_path().u8string() + "/../licensePlate";

  if (fs::exists(_cur_path))
    {
      _cfg = _cur_path + "/model/yolov2.cfg";
      _weight = _cur_path + "/model/yolov3-tiny_140000.weights";
      _labels = _cur_path + "/model/voc.names";
      _detector = new Detector(_cfg, _weight);
    }
  else
    _detector = nullptr;
}

void qimageToMat(const QImage& image, cv::OutputArray out)
{
  cv::Mat mat;
  cv::Size size(image.width(), image.height());

  switch (image.format())
    {
    case QImage::Format_Invalid:
    {
      mat.copyTo(out);
      break;
    }

    // 8 bit 4 channels
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
    {
      mat = cv::Mat(size,
                    CV_8UC4,
                    const_cast<uchar *>(image.constBits()),
                    static_cast<size_t>(image.bytesPerLine()));
      mat.copyTo(out);
      break;
    }

    // 8 bit 3 channels
    case QImage::Format_RGB888:
    {
      mat = cv::Mat(size,
                    CV_8UC3,
                    const_cast<uchar *>(image.constBits()),
                    static_cast<size_t>(image.bytesPerLine()));
      mat.copyTo(out);
      break;
    }

    // 8 bit 1 channel
    case QImage::Format_Indexed8:
    {
      mat = cv::Mat(size,
                    CV_8UC1,
                    const_cast<uchar *>(image.constBits()),
                    static_cast<size_t>(image.bytesPerLine()));
      mat.copyTo(out);
      break;
    }

    default:
    {
      qWarning() << "QImage to OpenCV format not handled:" << image.format();
      break;
    }
    }
}

void licensePlateDialog::clearTXT()
{
  ui->m_txtResult->clear();
  _resultStr = ui->m_txtResult->toPlainText();
}

void licensePlateDialog::backSpaceforTXT()
{
  QTextCursor cursor = ui->m_txtResult->textCursor();

  cursor.deletePreviousChar();
  _resultStr = ui->m_txtResult->toPlainText();
  ui->m_txtResult->setTextCursor(cursor);
}

void licensePlateDialog::PaymentBtnClicked()
{
  QString btnName = QObject::sender()->objectName();
  QStringList bottom_parts = btnName.split('_');
  QString lastPart = bottom_parts.last();
  QChar c = lastPart[lastPart.size() - 1];

  _resultStr += c;

  ui->m_txtResult->setText(_resultStr);
  QTextCursor cursor = QTextCursor(ui->m_txtResult->document());

  cursor.movePosition(QTextCursor::End);
  ui->m_txtResult->setTextCursor(cursor);
}

void licensePlateDialog::ProcessCapturedImage(int requestId, QImage img)
{
  Q_UNUSED(requestId);
  const QImage ScaleImg = img.scaled(ui->m_camArea->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
  qimageToMat(ScaleImg, _testImg);
}

void licensePlateDialog::StartCamera()
{
  const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

  for (const QCameraInfo& cameraInfo : cameras)
    {
      qDebug() << "cameraInfo.deviceName: " << cameraInfo.deviceName();
    }

  qDebug() << "error: " << _camera->error() <<
    "\n state:" << _camera->state() <<
    "\n status: " << _camera->status() <<
    "\n errorstring: " << _camera->errorString() <<
    "\n camptureMode: " << _camera->captureMode() <<
    "\n camera.lockStatus: " << _camera->lockStatus() <<
    "\n availableMetaData: " << _camera->availableMetaData() <<
    "\n camera.isAvailable: " << _camera->isAvailable() <<
    "\n viewfinder.isEnabled: " << _cameraViewFinder->isEnabled() <<
    "\n viewfinder.isVisible: " << _cameraViewFinder->isVisible();
  _camera->start();
}

void licensePlateDialog::StopCamera()
{
  _camera->stop();
}

void licensePlateDialog::CaptureImage()
{
  _imageCapture->capture();
  std::ifstream labelfile(_labels);

  if (labelfile.is_open() && !_testImg.empty() && _detector)  // Make sure test
                                                              // image is ready
                                                              // and darknet is
                                                              // ready
    {
      std::string line;

      while (std::getline(labelfile, line))
        {
          _classnames.push_back(line);
        }

      image_t img;
      img.h = _testImg.rows;
      img.w = _testImg.cols;
      img.c = _testImg.channels();
      img.data = (float *)(_testImg.data);
      std::vector<bbox_t> box = _detector->detect(img, 0.7f);
      std::map<int, std::string> mapPlate;

      ui->stackedWidget->setCurrentIndex(payPage);
    }
}

licensePlateDialog::~licensePlateDialog()
{
  delete ui;
  delete  _imageCapture;
}
