#ifndef LICENSEPLATEDIALOG_H
#define LICENSEPLATEDIALOG_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QCameraInfo>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <yolo/yolo.h>
QT_BEGIN_NAMESPACE
namespace Ui { class licensePlateDialog; }
QT_END_NAMESPACE

class licensePlateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit licensePlateDialog(QWidget *parent = nullptr);
    ~licensePlateDialog();
public:
    void StartCamera();
    void StopCamera();
    bool detectbyYOLO();
private slots:
    void processCapturedImage(int requestId, const QImage& img);
private:
    Ui::licensePlateDialog *ui;
    QCamera* _camera = nullptr;
    cv::VideoCapture* _videocapture = nullptr;
    QCameraViewfinder* _cameraViewFinder = nullptr;
    QVBoxLayout* _layout = nullptr;
    QCameraImageCapture* _imageCapture = nullptr;
};
#endif // LICENSEPLATEDIALOG_H
