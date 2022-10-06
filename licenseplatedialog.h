#ifndef LICENSEPLATEDIALOG_H
#define LICENSEPLATEDIALOG_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class licensePlateDialog; }
QT_END_NAMESPACE

class licensePlateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit licensePlateDialog(QWidget *parent = nullptr);
    ~licensePlateDialog();
private:
    void StartCamera();
    void StopCamera();
    void ProcessCapturedImage(int requestId, QImage img);
    void CaptureImage();
    void PaymentBtnClicked();
    void backSpaceforTXT();
private:
    Ui::licensePlateDialog *ui;
    QCamera* _camera;
    QCameraViewfinder* _cameraViewFinder;
    QVBoxLayout* _layout;
    QCameraImageCapture* _imageCapture;
    QString _resultStr;
};
#endif // LICENSEPLATEDIALOG_H
