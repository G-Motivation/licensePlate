#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"
#define cameraPage 0
#define payPage 1

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
    //Capture image from camera
    _imageCapture = new QCameraImageCapture(_camera);
     connect(_imageCapture, &QCameraImageCapture::imageCaptured, this, &licensePlateDialog::ProcessCapturedImage);
    connect(ui->m_btnStart, &QPushButton::clicked, this, &licensePlateDialog::StartCamera);
    connect(ui->m_btnStop, &QPushButton::clicked, this, &licensePlateDialog::StopCamera);
    connect(ui->m_btnCapture, &QPushButton::clicked, this, &licensePlateDialog::CaptureImage);
    connect(ui->m_btnBack, &QPushButton::clicked, this, &licensePlateDialog::backSpaceforTXT);

    std::vector<QPushButton*> btns {ui->m_btn0, ui->m_btn1, ui->m_btn2, ui->m_btn3, ui->m_btn4, ui->m_btn5, ui->m_btn6, ui->m_btn7,
                                                              ui->m_btn8, ui->m_btn9, ui->m_btnA, ui->m_btnB, ui->m_btnC, ui->m_btnD, ui->m_btnE, ui->m_btnF,
                                                              ui->m_btnG, ui->m_btnH, ui->m_btnI, ui->m_btnJ, ui->m_btnK, ui->m_btnL, ui->m_btnM, ui->m_btnN,
                                                              ui->m_btnO, ui->m_btnP, ui->m_btnQ, ui->m_btnR, ui->m_btnS, ui->m_btnT, ui->m_btnU, ui->m_btnV,
                                                              ui->m_btnW, ui->m_btnX, ui->m_btnY, ui->m_btnZ};
   for(auto& btn : btns)
   {
        connect(btn, &QPushButton::clicked, this, &licensePlateDialog::PaymentBtnClicked);
   }
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
    const char* index = btnName.mid(5,  -1).toStdString().c_str();

    switch(*index)
    {
        case '0':
            _resultStr += "0";
            break;
        case '1':
            _resultStr += "0";
            break;
        case '2':
            _resultStr += "2";
            break;
        case '3':
            _resultStr += "3";
            break;
        case '4':
            _resultStr += "4";
            break;
        case '5':
            _resultStr += "5";
            break;
        case '6':
            _resultStr += "6";
            break;
        case '7':
            _resultStr += "7";
            break;
        case '8':
            _resultStr += "8";
            break;
        case '9':
            _resultStr += "9";
            break;
        case 'A':
            _resultStr += "A";
            break;
        case 'B':
            _resultStr += "B";
            break;
        case 'C':
            _resultStr += "C";
            break;
        case 'D':
            _resultStr += "D";
            break;
        case 'E':
            _resultStr += "E";
            break;
        case 'F':
            _resultStr += "F";
            break;
        case 'G':
            _resultStr += "G";
            break;
        case 'H':
            _resultStr += "H";
            break;
        case 'I':
            _resultStr += "I";
            break;
        case 'J':
            _resultStr += "J";
            break;
        case 'K':
            _resultStr += "K";
            break;
        case 'L':
            _resultStr += "L";
            break;
        case 'M':
            _resultStr += "M";
            break;
        case 'N':
            _resultStr += "N";
            break;
        case 'O':
            _resultStr += "O";
            break;
        case 'P':
            _resultStr += "P";
            break;
        case 'Q':
            _resultStr += "Q";
            break;
        case 'R':
            _resultStr += "R";
            break;
        case 'S':
            _resultStr += "S";
            break;
        case 'T':
            _resultStr += "T";
            break;
        case 'U':
            _resultStr += "U";
            break;
        case 'V':
            _resultStr += "V";
            break;
        case 'W':
            _resultStr += "W";
            break;
        case 'X':
            _resultStr += "X";
            break;
        case 'Y':
            _resultStr += "Y";
            break;
        case 'Z':
            _resultStr += "Z";
            break;
    }
    ui->m_txtResult->setText(_resultStr);
     QTextCursor cursor = QTextCursor(ui->m_txtResult->document());
     cursor.movePosition(QTextCursor::End);
     ui->m_txtResult->setTextCursor(cursor);
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
      ui->stackedWidget->setCurrentIndex(payPage);
}

licensePlateDialog::~licensePlateDialog()
{
    delete ui;
    delete  _imageCapture;
}

