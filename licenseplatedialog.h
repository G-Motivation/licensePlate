#ifndef LICENSEPLATEDIALOG_H
#define LICENSEPLATEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class licensePlateDialog; }
QT_END_NAMESPACE

class licensePlateDialog : public QDialog
{
    Q_OBJECT

public:
    licensePlateDialog(QWidget *parent = nullptr);
    ~licensePlateDialog();

private:
    Ui::licensePlateDialog *ui;
};
#endif // LICENSEPLATEDIALOG_H
