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

    connect(ui->m_btnStart, &QPushButton::clicked, this, &licensePlateDialog::StartCamera);
    connect(ui->m_btnStop, &QPushButton::clicked, this, &licensePlateDialog::StopCamera);
}

void licensePlateDialog::ProcessCapturedImage(int requestId,  QImage img)
{
    Q_UNUSED(requestId);
    const QImage ScaleImg = img.scaled(_cameraViewFinder->size(),
                                                    Qt::KeepAspectRatio,
                                                    Qt::SmoothTransformation);
    const QPixmap Pixm = QPixmap::fromImage(ScaleImg);
    Pixm.save("C:/Users/Willy/Desktop/xx.jpg");

}

void licensePlateDialog::StartCamera()
{
    _camera->start();
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
        //Capture image from camera
        _imageCapture = new QCameraImageCapture(_camera);
        _imageCapture->capture();
        connect(_imageCapture, SIGNAL(imageCaptured(int,QImage)),
                                this, SLOT(ProcessCapturedImage(int,QImage)));
        delete  _imageCapture;
        _imageCapture = nullptr;
}

void licensePlateDialog::StopCamera()
{
    _camera->stop();
}

licensePlateDialog::~licensePlateDialog()
{
    delete ui;
}

