#ifndef LICENSEPLATEDIALOG_H
#define LICENSEPLATEDIALOG_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QCameraInfo>
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
private:
    Ui::licensePlateDialog *ui;
    QCamera* _camera;
    QCameraViewfinder* _cameraViewFinder;
    QVBoxLayout* _layout;
};
#endif // LICENSEPLATEDIALOG_H
