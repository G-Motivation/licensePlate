#ifndef LICENSEPLATEDIALOG_H
#define LICENSEPLATEDIALOG_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QCameraInfo>
#include <QCameraImageCapture>
QT_BEGIN_NAMESPACE
namespace Ui { class licensePlateDialog; }
QT_END_NAMESPACE

class licensePlateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit licensePlateDialog(QWidget *parent = nullptr);
    ~licensePlateDialog();
private slots:
    void StartCamera();
    void StopCamera();
    void ProcessCapturedImage(int requestId, QImage img);
private:
    Ui::licensePlateDialog *ui;
    QCamera* _camera;
    QCameraViewfinder* _cameraViewFinder;
    QVBoxLayout* _layout;
    QCameraImageCapture* _imageCapture;
};
#endif // LICENSEPLATEDIALOG_H
