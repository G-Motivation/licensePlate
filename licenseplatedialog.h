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
#include <opencv2/imgproc.hpp>
#include <yolo_v2_class.hpp>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <qdir.h>

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
void clearTXT();
void OK2Pay();
void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
                int current_det_fps = -1, int current_cap_fps = -1);
cv::Scalar obj_id_to_color(int obj_id);
private:
Ui::licensePlateDialog *ui = nullptr;
QCamera* _camera = nullptr;
QCameraViewfinder* _cameraViewFinder = nullptr;
QVBoxLayout* _layout = nullptr;
QCameraImageCapture* _imageCapture = nullptr;
QString _resultStr = "";
Detector* _detector = nullptr;
std::string _cur_path = "";
std::string _cfg = "";
std::string _weight = "";
std::string _labels = "";
std::vector<std::string> _classnames {};
cv::Mat _testImg;
};
#endif // LICENSEPLATEDIALOG_H
