#include "licenseplatedialog.h"
#include "ui_licenseplatedialog.h"

licensePlateDialog::licensePlateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::licensePlateDialog)
{
    ui->setupUi(this);
}

licensePlateDialog::~licensePlateDialog()
{
    delete ui;
}

