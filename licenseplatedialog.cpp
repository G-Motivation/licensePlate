#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"
#include <fstream>
#include <filesystem>
#define cameraPage 0
#define payPage 1
namespace fs = std::filesystem;

typedef struct _LicenseInfo //假定資料庫儲存內容
{
  QString ID;
  QString LicenseNum;
  QString Dateandtime;
} LicenseInfo;

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

  connect(ui->m_btnOK, &QPushButton::clicked, this, &licensePlateDialog::OK2Pay);

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

void licensePlateDialog::OK2Pay()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

  db.setDatabaseName(QDir::currentPath() + "/database/" + "LICENSE.db");
  if (!db.open())
    return;

  QSqlQuery query;
  query.prepare("INSERT INTO LICENSE (id, licenseNum, dateandtime) VALUES (:id, :licenseNum, :dateandtime)");
  /*query.bindValue(":id", "user4");
     query.bindValue(":licenseNum", "192.168.1.5");
     query.bindValue(":dateandtime", "5004");*/
  query.exec();
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
  /*const QImage ScaleImg = img.scaled(ui->m_camArea->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
     qimageToMat(ScaleImg, _testImg);*/

  _testImg = cv::imread((QDir::currentPath() + "/googletest/" + "TestLicense.jpg").toStdString());
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

  _camera->setViewfinder(_cameraViewFinder);
  _camera->setCaptureMode(QCamera::CaptureViewfinder);
  _camera->start();
}

void licensePlateDialog::StopCamera()
{
  _camera->stop();
}

cv::Scalar licensePlateDialog::obj_id_to_color(int obj_id)
{
  int const colors[6][3] = { { 1, 0, 1 }, { 0, 0, 1 }, { 0, 1, 1 }, { 0, 1, 0 }, { 1, 1, 0 }, { 1, 0, 0 } };
  int const offset = obj_id * 123457 % 6;
  int const color_scale = 150 + (obj_id * 123457) % 100;
  cv::Scalar color(colors[offset][0], colors[offset][1], colors[offset][2]);
  color *= color_scale;
  return color;
}

void licensePlateDialog::draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
                                    int current_det_fps, int current_cap_fps)
{
  int const colors[6][3] = { { 1, 0, 1 }, { 0, 0, 1 }, { 0, 1, 1 }, { 0, 1, 0 }, { 1, 1, 0 }, { 1, 0, 0 } };
//https://zhuanlan.zhihu.com/p/135380256
  for (auto &i : result_vec)
    {
      cv::Scalar color = obj_id_to_color(i.obj_id);
      cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
      if (obj_names.size() > i.obj_id)
        {
          std::string obj_name = obj_names[i.obj_id];
          if (i.track_id > 0)
            obj_name += " - " + std::to_string(i.track_id);
          cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
          int max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
          max_width = std::max(max_width, (int)i.w + 2);
          //max_width = std::max(max_width, 283);
          std::string coords_3d;
          if (!std::isnan(i.z_3d))
            {
              std::stringstream ss;
              ss << std::fixed << std::setprecision(2) << "x:" << i.x_3d << "m y:" << i.y_3d << "m z:" << i.z_3d << "m ";
              coords_3d = ss.str();
              cv::Size const text_size_3d = getTextSize(ss.str(), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, 1, 0);
              int const max_width_3d = (text_size_3d.width > i.w + 2) ? text_size_3d.width : (i.w + 2);
              if (max_width_3d > max_width)
                max_width = max_width_3d;
            }
          cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 35, 0)),
                        cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
                        color, cv::FILLED, 8, 0);
          putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 16), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
          if (!coords_3d.empty())
            putText(mat_img, coords_3d, cv::Point2f(i.x, i.y - 1), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(0, 0, 0), 1);
        }
    }
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

      draw_boxes(_testImg, box, _classnames);

      ui->stackedWidget->setCurrentIndex(payPage);
    }
}

licensePlateDialog::~licensePlateDialog()
{
  delete ui;
  delete  _imageCapture;
}
