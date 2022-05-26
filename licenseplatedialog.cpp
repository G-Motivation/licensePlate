#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"
#include <experimental/filesystem>
#define cameraPage 0
#define payPage 1
namespace fs = std::experimental::filesystem::v1;

void licensePlateDialog::detectbyYOLO()
{
    try
    {
        const std::string YOLO_MODEL = ".//model";
        fs::path file_model((YOLO_MODEL+ "//yolo-fastest-xl.onnx").c_str());
        fs::path file_coco((YOLO_MODEL + "//coco.names").c_str());
        if (!fs::exists(file_model) && !fs::exists(file_coco))
            throw fs::filesystem_error("File not exist", std::error_code());

        CV_DNN_REGISTER_LAYER_CLASS(Exp, ExpLayer);
        Net_config yolo_nets[1] = {
            { 0.5f, 0.3f, 320, 320, YOLO_MODEL + "//coco.names", YOLO_MODEL+ "//yolo-fastest-xl.onnx",
            YOLO_MODEL + "yolo-fastest-xl.onnx", YOLO_MODEL + "yolo-fastest-xl" }
        };
        YOLO yolo(yolo_nets[0]);
    }
    catch(fs::filesystem_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
licensePlateDialog::licensePlateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::licensePlateDialog)
{
    ui->setupUi(this);

    _camera = new QCamera(this);
    _cameraViewFinder = new QCameraViewfinder(this);
    _imageCapture=new QCameraImageCapture(_camera);
    _layout = new QVBoxLayout;

    _camera->setViewfinder(_cameraViewFinder);
    _layout->addWidget(_cameraViewFinder);
    _layout->setMargin(0);
    ui->m_camArea->setLayout(_layout);
    ui->stackedWidget->setCurrentIndex(cameraPage);

    connect(ui->m_btnStart, &QPushButton::clicked, this, &licensePlateDialog::StartCamera);
    connect(ui->m_btnStop, &QPushButton::clicked, this, &licensePlateDialog::StopCamera);
    connect(_imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(processCapturedImage(int,QImage)));
    detectbyYOLO();
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
    _imageCapture->capture();
}

void licensePlateDialog::StopCamera()
{
    _camera->stop();
}

void qimage_to_mat(const QImage& image, cv::OutputArray out)
{

    switch(image.format()) {
        case QImage::Format_Invalid:
        {
            cv::Mat empty;
            empty.copyTo(out);
            break;
        }
        case QImage::Format_RGB32:
        {
            cv::Mat view(image.height(),image.width(),CV_8UC4,(void *)image.constBits(),image.bytesPerLine());
            view.copyTo(out);
            break;
        }
        case QImage::Format_RGB888:
        {
            cv::Mat view(image.height(),image.width(),CV_8UC3,(void *)image.constBits(),image.bytesPerLine());
            cvtColor(view, out, cv::COLOR_RGB2BGR);
            break;
        }
        default:
        {
            QImage conv = image.convertToFormat(QImage::Format_ARGB32);
            cv::Mat view(conv.height(),conv.width(),CV_8UC4,(void *)conv.constBits(),conv.bytesPerLine());
            view.copyTo(out);
            break;
        }
    }
}

void licensePlateDialog::processCapturedImage(int requestId, const QImage& img)
{
    Q_UNUSED(requestId);
    cv::Mat captureImg;
    QImage scaledImage = img.scaled(ui->m_camArea->size(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation);
    //qimage_to_mat(scaledImage, captureImg);
    //cv::imshow("Show Img", captureImg);

}

licensePlateDialog::~licensePlateDialog()
{
    delete ui;
}

