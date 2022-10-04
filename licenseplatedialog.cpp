#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"
#define cameraPage 0
#define payPage 1

licensePlateDialog::licensePlateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::licensePlateDialog)
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
    //Capture image from camera
    _imageCapture = new QCameraImageCapture(_camera);
     connect(_imageCapture, &QCameraImageCapture::imageCaptured, this, &licensePlateDialog::ProcessCapturedImage);
    connect(ui->m_btnStart, &QPushButton::clicked, this, &licensePlateDialog::StartCamera);
    connect(ui->m_btnStop, &QPushButton::clicked, this, &licensePlateDialog::StopCamera);
    connect(ui->m_btnCapture, &QPushButton::clicked, this, &licensePlateDialog::CaptureImage);
}
void qimageToMat(const QImage& image, cv::OutputArray out)
{
    cv::Mat mat;
    cv::Size size(image.width(), image.height());
    switch(image.format())
    {
        case QImage::Format_Invalid:
        {
            mat.copyTo(out);
            break;
        }
        //8 bit 4 channels
        case QImage::Format_ARGB32:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
        {
            mat = cv::Mat(size, CV_8UC4, const_cast<uchar*>(image.constBits()), static_cast<size_t>(image.bytesPerLine()));
            mat.copyTo(out);
            break;
        }
        //8 bit 3 channels
        case QImage::Format_RGB888:
        {
            mat = cv::Mat(size, CV_8UC3, const_cast<uchar*>(image.constBits()), static_cast<size_t>(image.bytesPerLine()));
            mat.copyTo(out);
            break;
        }
        //8 bit 1 channel
        case QImage::Format_Indexed8:
        {
            mat = cv::Mat(size, CV_8UC1, const_cast<uchar*>(image.constBits()), static_cast<size_t>(image.bytesPerLine()));
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
void licensePlateDialog::ProcessCapturedImage(int requestId,  QImage img)
{
    Q_UNUSED(requestId);
    const QImage ScaleImg = img.scaled( ui->m_camArea->size(),
                                                    Qt::KeepAspectRatio,
                                                    Qt::SmoothTransformation);
    cv::Mat out;
    qimageToMat(ScaleImg,  out);
}

void licensePlateDialog::StartCamera()
{
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    for (const QCameraInfo &cameraInfo : cameras) {
        qDebug() << "cameraInfo.deviceName: "<< cameraInfo.deviceName();
    }

    qDebug() << "error: " <<_camera->error() <<
        "\n state:" << _camera->state() <<
        "\n status: " << _camera->status() <<
        "\n errorstring: " << _camera->errorString() <<
        "\n camptureMode: " << _camera->captureMode() <<
        "\n camera.lockStatus: " << _camera->lockStatus() <<
        "\n availableMetaData: " << _camera->availableMetaData() <<
        "\n camera.isAvailable: " << _camera->isAvailable() <<
        "\n viewfinder.isEnabled: "<< _cameraViewFinder->isEnabled() <<
        "\n viewfinder.isVisible: " <<_cameraViewFinder->isVisible();
        _camera->start();
}

void licensePlateDialog::StopCamera()
{
    _camera->stop();
}

void licensePlateDialog::CaptureImage()
{
      _imageCapture->capture();
}

licensePlateDialog::~licensePlateDialog()
{
    delete ui;
    delete  _imageCapture;
}

