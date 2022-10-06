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
#include <QtWidgets/QTextEdit>
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
    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPushButton *m_btn4;
    QPushButton *m_btn2;
    QPushButton *m_btn3;
    QPushButton *m_btn5;
    QPushButton *m_btn8;
    QPushButton *m_btn7;
    QPushButton *m_btn6;
    QPushButton *m_btn9;
    QPushButton *m_btnA;
    QPushButton *m_btnB;
    QPushButton *m_btnC;
    QPushButton *m_btnD;
    QPushButton *m_btnE;
    QPushButton *m_btnF;
    QPushButton *m_btnG;
    QPushButton *m_btnH;
    QPushButton *m_btnI;
    QPushButton *m_btnJ;
    QPushButton *m_btnK;
    QPushButton *m_btnL;
    QPushButton *m_btnM;
    QPushButton *m_btnN;
    QPushButton *m_btnO;
    QPushButton *m_btnP;
    QPushButton *m_btnQ;
    QPushButton *m_btnR;
    QPushButton *m_btnS;
    QPushButton *m_btnT;
    QPushButton *m_btnU;
    QPushButton *m_btnV;
    QPushButton *m_btnW;
    QPushButton *m_btnBack;
    QPushButton *m_btnClear;
    QTextEdit *m_txtResult;
    QPushButton *m_btnOK;
    QPushButton *m_btnX;
    QPushButton *m_btnY;
    QPushButton *m_btnZ;

    void setupUi(QDialog *licensePlateDialog)
    {
        if (licensePlateDialog->objectName().isEmpty())
            licensePlateDialog->setObjectName(QString::fromUtf8("licensePlateDialog"));
        licensePlateDialog->resize(810, 600);
        stackedWidget = new QStackedWidget(licensePlateDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 10, 771, 581));
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
        m_btn0 = new QPushButton(payPage);
        m_btn0->setObjectName(QString::fromUtf8("m_btn0"));
        m_btn0->setGeometry(QRect(0, 160, 71, 51));
        m_btn1 = new QPushButton(payPage);
        m_btn1->setObjectName(QString::fromUtf8("m_btn1"));
        m_btn1->setGeometry(QRect(90, 160, 71, 51));
        m_btn4 = new QPushButton(payPage);
        m_btn4->setObjectName(QString::fromUtf8("m_btn4"));
        m_btn4->setGeometry(QRect(360, 160, 71, 51));
        m_btn2 = new QPushButton(payPage);
        m_btn2->setObjectName(QString::fromUtf8("m_btn2"));
        m_btn2->setGeometry(QRect(180, 160, 71, 51));
        m_btn3 = new QPushButton(payPage);
        m_btn3->setObjectName(QString::fromUtf8("m_btn3"));
        m_btn3->setGeometry(QRect(270, 160, 71, 51));
        m_btn5 = new QPushButton(payPage);
        m_btn5->setObjectName(QString::fromUtf8("m_btn5"));
        m_btn5->setGeometry(QRect(440, 160, 71, 51));
        m_btn8 = new QPushButton(payPage);
        m_btn8->setObjectName(QString::fromUtf8("m_btn8"));
        m_btn8->setGeometry(QRect(680, 160, 71, 51));
        m_btn7 = new QPushButton(payPage);
        m_btn7->setObjectName(QString::fromUtf8("m_btn7"));
        m_btn7->setGeometry(QRect(600, 160, 71, 51));
        m_btn6 = new QPushButton(payPage);
        m_btn6->setObjectName(QString::fromUtf8("m_btn6"));
        m_btn6->setGeometry(QRect(520, 160, 71, 51));
        m_btn9 = new QPushButton(payPage);
        m_btn9->setObjectName(QString::fromUtf8("m_btn9"));
        m_btn9->setGeometry(QRect(0, 220, 71, 51));
        m_btnA = new QPushButton(payPage);
        m_btnA->setObjectName(QString::fromUtf8("m_btnA"));
        m_btnA->setGeometry(QRect(90, 220, 71, 51));
        m_btnB = new QPushButton(payPage);
        m_btnB->setObjectName(QString::fromUtf8("m_btnB"));
        m_btnB->setGeometry(QRect(180, 220, 71, 51));
        m_btnC = new QPushButton(payPage);
        m_btnC->setObjectName(QString::fromUtf8("m_btnC"));
        m_btnC->setGeometry(QRect(270, 220, 71, 51));
        m_btnD = new QPushButton(payPage);
        m_btnD->setObjectName(QString::fromUtf8("m_btnD"));
        m_btnD->setGeometry(QRect(360, 220, 71, 51));
        m_btnE = new QPushButton(payPage);
        m_btnE->setObjectName(QString::fromUtf8("m_btnE"));
        m_btnE->setGeometry(QRect(440, 220, 71, 51));
        m_btnF = new QPushButton(payPage);
        m_btnF->setObjectName(QString::fromUtf8("m_btnF"));
        m_btnF->setGeometry(QRect(520, 220, 71, 51));
        m_btnG = new QPushButton(payPage);
        m_btnG->setObjectName(QString::fromUtf8("m_btnG"));
        m_btnG->setGeometry(QRect(600, 220, 71, 51));
        m_btnH = new QPushButton(payPage);
        m_btnH->setObjectName(QString::fromUtf8("m_btnH"));
        m_btnH->setGeometry(QRect(680, 220, 71, 51));
        m_btnI = new QPushButton(payPage);
        m_btnI->setObjectName(QString::fromUtf8("m_btnI"));
        m_btnI->setGeometry(QRect(0, 280, 71, 51));
        m_btnJ = new QPushButton(payPage);
        m_btnJ->setObjectName(QString::fromUtf8("m_btnJ"));
        m_btnJ->setGeometry(QRect(90, 280, 71, 51));
        m_btnK = new QPushButton(payPage);
        m_btnK->setObjectName(QString::fromUtf8("m_btnK"));
        m_btnK->setGeometry(QRect(180, 280, 71, 51));
        m_btnL = new QPushButton(payPage);
        m_btnL->setObjectName(QString::fromUtf8("m_btnL"));
        m_btnL->setGeometry(QRect(270, 280, 71, 51));
        m_btnM = new QPushButton(payPage);
        m_btnM->setObjectName(QString::fromUtf8("m_btnM"));
        m_btnM->setGeometry(QRect(360, 280, 71, 51));
        m_btnN = new QPushButton(payPage);
        m_btnN->setObjectName(QString::fromUtf8("m_btnN"));
        m_btnN->setGeometry(QRect(440, 280, 71, 51));
        m_btnO = new QPushButton(payPage);
        m_btnO->setObjectName(QString::fromUtf8("m_btnO"));
        m_btnO->setGeometry(QRect(520, 280, 71, 51));
        m_btnP = new QPushButton(payPage);
        m_btnP->setObjectName(QString::fromUtf8("m_btnP"));
        m_btnP->setGeometry(QRect(600, 280, 71, 51));
        m_btnQ = new QPushButton(payPage);
        m_btnQ->setObjectName(QString::fromUtf8("m_btnQ"));
        m_btnQ->setGeometry(QRect(680, 280, 71, 51));
        m_btnR = new QPushButton(payPage);
        m_btnR->setObjectName(QString::fromUtf8("m_btnR"));
        m_btnR->setGeometry(QRect(0, 340, 71, 51));
        m_btnS = new QPushButton(payPage);
        m_btnS->setObjectName(QString::fromUtf8("m_btnS"));
        m_btnS->setGeometry(QRect(90, 340, 71, 51));
        m_btnT = new QPushButton(payPage);
        m_btnT->setObjectName(QString::fromUtf8("m_btnT"));
        m_btnT->setGeometry(QRect(180, 340, 71, 51));
        m_btnU = new QPushButton(payPage);
        m_btnU->setObjectName(QString::fromUtf8("m_btnU"));
        m_btnU->setGeometry(QRect(270, 340, 71, 51));
        m_btnV = new QPushButton(payPage);
        m_btnV->setObjectName(QString::fromUtf8("m_btnV"));
        m_btnV->setGeometry(QRect(360, 340, 71, 51));
        m_btnW = new QPushButton(payPage);
        m_btnW->setObjectName(QString::fromUtf8("m_btnW"));
        m_btnW->setGeometry(QRect(440, 340, 71, 51));
        m_btnBack = new QPushButton(payPage);
        m_btnBack->setObjectName(QString::fromUtf8("m_btnBack"));
        m_btnBack->setGeometry(QRect(590, 470, 71, 51));
        QFont font;
        font.setPointSize(13);
        m_btnBack->setFont(font);
        m_btnBack->setIconSize(QSize(16, 16));
        m_btnClear = new QPushButton(payPage);
        m_btnClear->setObjectName(QString::fromUtf8("m_btnClear"));
        m_btnClear->setGeometry(QRect(680, 470, 71, 51));
        m_btnClear->setFont(font);
        m_btnClear->setIconSize(QSize(16, 16));
        m_txtResult = new QTextEdit(payPage);
        m_txtResult->setObjectName(QString::fromUtf8("m_txtResult"));
        m_txtResult->setGeometry(QRect(10, 30, 391, 41));
        m_btnOK = new QPushButton(payPage);
        m_btnOK->setObjectName(QString::fromUtf8("m_btnOK"));
        m_btnOK->setGeometry(QRect(440, 30, 71, 51));
        m_btnOK->setFont(font);
        m_btnOK->setIconSize(QSize(16, 16));
        m_btnX = new QPushButton(payPage);
        m_btnX->setObjectName(QString::fromUtf8("m_btnX"));
        m_btnX->setGeometry(QRect(520, 340, 71, 51));
        m_btnY = new QPushButton(payPage);
        m_btnY->setObjectName(QString::fromUtf8("m_btnY"));
        m_btnY->setGeometry(QRect(600, 340, 71, 51));
        m_btnZ = new QPushButton(payPage);
        m_btnZ->setObjectName(QString::fromUtf8("m_btnZ"));
        m_btnZ->setGeometry(QRect(680, 340, 71, 51));
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
        m_btn0->setText(QCoreApplication::translate("licensePlateDialog", "0", nullptr));
        m_btn1->setText(QCoreApplication::translate("licensePlateDialog", "1", nullptr));
        m_btn4->setText(QCoreApplication::translate("licensePlateDialog", "4", nullptr));
        m_btn2->setText(QCoreApplication::translate("licensePlateDialog", "2", nullptr));
        m_btn3->setText(QCoreApplication::translate("licensePlateDialog", "3", nullptr));
        m_btn5->setText(QCoreApplication::translate("licensePlateDialog", "5", nullptr));
        m_btn8->setText(QCoreApplication::translate("licensePlateDialog", "8", nullptr));
        m_btn7->setText(QCoreApplication::translate("licensePlateDialog", "7", nullptr));
        m_btn6->setText(QCoreApplication::translate("licensePlateDialog", "6", nullptr));
        m_btn9->setText(QCoreApplication::translate("licensePlateDialog", "9", nullptr));
        m_btnA->setText(QCoreApplication::translate("licensePlateDialog", "A", nullptr));
        m_btnB->setText(QCoreApplication::translate("licensePlateDialog", "B", nullptr));
        m_btnC->setText(QCoreApplication::translate("licensePlateDialog", "C", nullptr));
        m_btnD->setText(QCoreApplication::translate("licensePlateDialog", "D", nullptr));
        m_btnE->setText(QCoreApplication::translate("licensePlateDialog", "E", nullptr));
        m_btnF->setText(QCoreApplication::translate("licensePlateDialog", "F", nullptr));
        m_btnG->setText(QCoreApplication::translate("licensePlateDialog", "G", nullptr));
        m_btnH->setText(QCoreApplication::translate("licensePlateDialog", "H", nullptr));
        m_btnI->setText(QCoreApplication::translate("licensePlateDialog", "I", nullptr));
        m_btnJ->setText(QCoreApplication::translate("licensePlateDialog", "J", nullptr));
        m_btnK->setText(QCoreApplication::translate("licensePlateDialog", "K", nullptr));
        m_btnL->setText(QCoreApplication::translate("licensePlateDialog", "L", nullptr));
        m_btnM->setText(QCoreApplication::translate("licensePlateDialog", "M", nullptr));
        m_btnN->setText(QCoreApplication::translate("licensePlateDialog", "N", nullptr));
        m_btnO->setText(QCoreApplication::translate("licensePlateDialog", "O", nullptr));
        m_btnP->setText(QCoreApplication::translate("licensePlateDialog", "P", nullptr));
        m_btnQ->setText(QCoreApplication::translate("licensePlateDialog", "Q", nullptr));
        m_btnR->setText(QCoreApplication::translate("licensePlateDialog", "R", nullptr));
        m_btnS->setText(QCoreApplication::translate("licensePlateDialog", "S", nullptr));
        m_btnT->setText(QCoreApplication::translate("licensePlateDialog", "T", nullptr));
        m_btnU->setText(QCoreApplication::translate("licensePlateDialog", "U", nullptr));
        m_btnV->setText(QCoreApplication::translate("licensePlateDialog", "V", nullptr));
        m_btnW->setText(QCoreApplication::translate("licensePlateDialog", "W", nullptr));
        m_btnBack->setText(QCoreApplication::translate("licensePlateDialog", "<-", nullptr));
        m_btnClear->setText(QCoreApplication::translate("licensePlateDialog", "clear", nullptr));
        m_btnOK->setText(QCoreApplication::translate("licensePlateDialog", "OK", nullptr));
        m_btnX->setText(QCoreApplication::translate("licensePlateDialog", "X", nullptr));
        m_btnY->setText(QCoreApplication::translate("licensePlateDialog", "Y", nullptr));
        m_btnZ->setText(QCoreApplication::translate("licensePlateDialog", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class licensePlateDialog: public Ui_licensePlateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSEPLATEDIALOG_H
