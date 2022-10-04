/********************************************************************************
** Form generated from reading UI file 'licenseplatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_licensePlateDialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *cameraPage;
    QScrollArea *m_camArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_btnStart;
    QPushButton *m_btnStop;
    QPushButton *m_btnCapture;
    QSpacerItem *horizontalSpacer_2;
    QWidget *payPage;

    void setupUi(QDialog *licensePlateDialog)
    {
        if (licensePlateDialog->objectName().isEmpty())
            licensePlateDialog->setObjectName(QString::fromUtf8("licensePlateDialog"));
        licensePlateDialog->resize(810, 600);
        stackedWidget = new QStackedWidget(licensePlateDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 10, 771, 581));
        cameraPage = new QWidget();
        cameraPage->setObjectName(QString::fromUtf8("cameraPage"));
        m_camArea = new QScrollArea(cameraPage);
        m_camArea->setObjectName(QString::fromUtf8("m_camArea"));
        m_camArea->setGeometry(QRect(120, 20, 551, 291));
        m_camArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 549, 289));
        m_camArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(cameraPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 410, 351, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_btnStart = new QPushButton(layoutWidget);
        m_btnStart->setObjectName(QString::fromUtf8("m_btnStart"));

        horizontalLayout->addWidget(m_btnStart);

        m_btnStop = new QPushButton(layoutWidget);
        m_btnStop->setObjectName(QString::fromUtf8("m_btnStop"));

        horizontalLayout->addWidget(m_btnStop);

        m_btnCapture = new QPushButton(layoutWidget);
        m_btnCapture->setObjectName(QString::fromUtf8("m_btnCapture"));

        horizontalLayout->addWidget(m_btnCapture);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(cameraPage);
        payPage = new QWidget();
        payPage->setObjectName(QString::fromUtf8("payPage"));
        stackedWidget->addWidget(payPage);

        retranslateUi(licensePlateDialog);

        QMetaObject::connectSlotsByName(licensePlateDialog);
    } // setupUi

    void retranslateUi(QDialog *licensePlateDialog)
    {
        licensePlateDialog->setWindowTitle(QCoreApplication::translate("licensePlateDialog", "licensePlateDialog", nullptr));
        m_btnStart->setText(QCoreApplication::translate("licensePlateDialog", "Camera Start", nullptr));
        m_btnStop->setText(QCoreApplication::translate("licensePlateDialog", "Camera Stop", nullptr));
        m_btnCapture->setText(QCoreApplication::translate("licensePlateDialog", "Capture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class licensePlateDialog: public Ui_licensePlateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEPLATEDIALOG_H
