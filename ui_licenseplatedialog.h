/********************************************************************************
** Form generated from reading UI file 'licenseplatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSEPLATEDIALOG_H
#define UI_LICENSEPLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_licensePlateDialog
{
public:
    QScrollArea *m_camArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_btnStart;
    QPushButton *m_btnStop;

    void setupUi(QDialog *licensePlateDialog)
    {
        if (licensePlateDialog->objectName().isEmpty())
            licensePlateDialog->setObjectName(QString::fromUtf8("licensePlateDialog"));
        licensePlateDialog->resize(800, 600);
        m_camArea = new QScrollArea(licensePlateDialog);
        m_camArea->setObjectName(QString::fromUtf8("m_camArea"));
        m_camArea->setGeometry(QRect(150, 50, 551, 291));
        m_camArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 549, 289));
        m_camArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(licensePlateDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(350, 370, 351, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_btnStart = new QPushButton(widget);
        m_btnStart->setObjectName(QString::fromUtf8("m_btnStart"));

        horizontalLayout->addWidget(m_btnStart);

        m_btnStop = new QPushButton(widget);
        m_btnStop->setObjectName(QString::fromUtf8("m_btnStop"));

        horizontalLayout->addWidget(m_btnStop);


        retranslateUi(licensePlateDialog);

        QMetaObject::connectSlotsByName(licensePlateDialog);
    } // setupUi

    void retranslateUi(QDialog *licensePlateDialog)
    {
        licensePlateDialog->setWindowTitle(QApplication::translate("licensePlateDialog", "licensePlateDialog", nullptr));
        m_btnStart->setText(QApplication::translate("licensePlateDialog", "Camera Start", nullptr));
        m_btnStop->setText(QApplication::translate("licensePlateDialog", "Camera Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class licensePlateDialog: public Ui_licensePlateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEPLATEDIALOG_H
