/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *COMPort;
    QLabel *label_2;
    QComboBox *BuadRate;
    QLabel *label_3;
    QComboBox *DataBit;
    QLabel *label_4;
    QComboBox *StopBit;
    QLabel *label_5;
    QComboBox *CheckBit;
    QLabel *label_6;
    QComboBox *StreamCtrl;
    QRadioButton *RadioAscii;
    QRadioButton *radioHex;
    QCheckBox *checkBoxRecordTime;
    QPushButton *MessageFilter;
    QLabel *label_7;
    QLabel *label_SendCount;
    QLabel *label_8;
    QLineEdit *Line_SendTimeGap;
    QLabel *label_9;
    QLineEdit *Line_UseTime;
    QPushButton *ButtonLink;
    QPushButton *ButtonStopSend;
    QPushButton *push_SendLoop;
    QPushButton *ButtonopenFile;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QTextEdit *Cmddisplay;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QRadioButton *radioSendHex;
    QTextEdit *SendTextEdit;
    QPushButton *ButtonSend;
    QPushButton *PushStopSend;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(686, 504);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        formGroupBox = new QGroupBox(centralWidget);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formGroupBox->sizePolicy().hasHeightForWidth());
        formGroupBox->setSizePolicy(sizePolicy);
        formGroupBox->setMaximumSize(QSize(180, 16777215));
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(formGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        COMPort = new QComboBox(formGroupBox);
        COMPort->setObjectName(QString::fromUtf8("COMPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, COMPort);

        label_2 = new QLabel(formGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        BuadRate = new QComboBox(formGroupBox);
        BuadRate->setObjectName(QString::fromUtf8("BuadRate"));

        formLayout->setWidget(2, QFormLayout::FieldRole, BuadRate);

        label_3 = new QLabel(formGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        DataBit = new QComboBox(formGroupBox);
        DataBit->setObjectName(QString::fromUtf8("DataBit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, DataBit);

        label_4 = new QLabel(formGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        StopBit = new QComboBox(formGroupBox);
        StopBit->setObjectName(QString::fromUtf8("StopBit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, StopBit);

        label_5 = new QLabel(formGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        CheckBit = new QComboBox(formGroupBox);
        CheckBit->setObjectName(QString::fromUtf8("CheckBit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, CheckBit);

        label_6 = new QLabel(formGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        StreamCtrl = new QComboBox(formGroupBox);
        StreamCtrl->setObjectName(QString::fromUtf8("StreamCtrl"));

        formLayout->setWidget(6, QFormLayout::FieldRole, StreamCtrl);

        RadioAscii = new QRadioButton(formGroupBox);
        RadioAscii->setObjectName(QString::fromUtf8("RadioAscii"));

        formLayout->setWidget(7, QFormLayout::LabelRole, RadioAscii);

        radioHex = new QRadioButton(formGroupBox);
        radioHex->setObjectName(QString::fromUtf8("radioHex"));

        formLayout->setWidget(7, QFormLayout::FieldRole, radioHex);

        checkBoxRecordTime = new QCheckBox(formGroupBox);
        checkBoxRecordTime->setObjectName(QString::fromUtf8("checkBoxRecordTime"));

        formLayout->setWidget(8, QFormLayout::LabelRole, checkBoxRecordTime);

        MessageFilter = new QPushButton(formGroupBox);
        MessageFilter->setObjectName(QString::fromUtf8("MessageFilter"));
        sizePolicy.setHeightForWidth(MessageFilter->sizePolicy().hasHeightForWidth());
        MessageFilter->setSizePolicy(sizePolicy);
        MessageFilter->setMinimumSize(QSize(60, 0));

        formLayout->setWidget(8, QFormLayout::FieldRole, MessageFilter);

        label_7 = new QLabel(formGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);

        label_SendCount = new QLabel(formGroupBox);
        label_SendCount->setObjectName(QString::fromUtf8("label_SendCount"));

        formLayout->setWidget(9, QFormLayout::FieldRole, label_SendCount);

        label_8 = new QLabel(formGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_8);

        Line_SendTimeGap = new QLineEdit(formGroupBox);
        Line_SendTimeGap->setObjectName(QString::fromUtf8("Line_SendTimeGap"));

        formLayout->setWidget(10, QFormLayout::FieldRole, Line_SendTimeGap);

        label_9 = new QLabel(formGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_9);

        Line_UseTime = new QLineEdit(formGroupBox);
        Line_UseTime->setObjectName(QString::fromUtf8("Line_UseTime"));

        formLayout->setWidget(11, QFormLayout::FieldRole, Line_UseTime);


        verticalLayout_2->addWidget(formGroupBox);

        ButtonLink = new QPushButton(centralWidget);
        ButtonLink->setObjectName(QString::fromUtf8("ButtonLink"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ButtonLink->sizePolicy().hasHeightForWidth());
        ButtonLink->setSizePolicy(sizePolicy1);
        ButtonLink->setMaximumSize(QSize(180, 16777215));
        ButtonLink->setLayoutDirection(Qt::LeftToRight);
        ButtonLink->setStyleSheet(QString::fromUtf8("QPushButton{ color: rgb(255, 0, 0)}"));

        verticalLayout_2->addWidget(ButtonLink);

        ButtonStopSend = new QPushButton(centralWidget);
        ButtonStopSend->setObjectName(QString::fromUtf8("ButtonStopSend"));
        sizePolicy1.setHeightForWidth(ButtonStopSend->sizePolicy().hasHeightForWidth());
        ButtonStopSend->setSizePolicy(sizePolicy1);
        ButtonStopSend->setMaximumSize(QSize(180, 16777215));
        ButtonStopSend->setStyleSheet(QString::fromUtf8("QPushButton{color:rgb(255, 170, 0)}"));

        verticalLayout_2->addWidget(ButtonStopSend);

        push_SendLoop = new QPushButton(centralWidget);
        push_SendLoop->setObjectName(QString::fromUtf8("push_SendLoop"));
        sizePolicy1.setHeightForWidth(push_SendLoop->sizePolicy().hasHeightForWidth());
        push_SendLoop->setSizePolicy(sizePolicy1);
        push_SendLoop->setMaximumSize(QSize(180, 16777215));

        verticalLayout_2->addWidget(push_SendLoop);

        ButtonopenFile = new QPushButton(centralWidget);
        ButtonopenFile->setObjectName(QString::fromUtf8("ButtonopenFile"));
        sizePolicy1.setHeightForWidth(ButtonopenFile->sizePolicy().hasHeightForWidth());
        ButtonopenFile->setSizePolicy(sizePolicy1);
        ButtonopenFile->setMaximumSize(QSize(180, 16777215));

        verticalLayout_2->addWidget(ButtonopenFile);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_11);

        Cmddisplay = new QTextEdit(centralWidget);
        Cmddisplay->setObjectName(QString::fromUtf8("Cmddisplay"));

        verticalLayout->addWidget(Cmddisplay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_10);

        radioSendHex = new QRadioButton(centralWidget);
        radioSendHex->setObjectName(QString::fromUtf8("radioSendHex"));

        horizontalLayout->addWidget(radioSendHex);


        verticalLayout->addLayout(horizontalLayout);

        SendTextEdit = new QTextEdit(centralWidget);
        SendTextEdit->setObjectName(QString::fromUtf8("SendTextEdit"));
        SendTextEdit->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(SendTextEdit);

        ButtonSend = new QPushButton(centralWidget);
        ButtonSend->setObjectName(QString::fromUtf8("ButtonSend"));
        sizePolicy1.setHeightForWidth(ButtonSend->sizePolicy().hasHeightForWidth());
        ButtonSend->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(ButtonSend);

        PushStopSend = new QPushButton(centralWidget);
        PushStopSend->setObjectName(QString::fromUtf8("PushStopSend"));
        sizePolicy1.setHeightForWidth(PushStopSend->sizePolicy().hasHeightForWidth());
        PushStopSend->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(PushStopSend);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, verticalLayout);


        gridLayout->addLayout(formLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 686, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        formGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\216\247", nullptr));
        RadioAscii->setText(QCoreApplication::translate("MainWindow", "Ascii", nullptr));
        radioHex->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        checkBoxRecordTime->setText(QCoreApplication::translate("MainWindow", "\350\256\260\345\275\225\346\227\266\351\227\264\346\210\263", nullptr));
        MessageFilter->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\241\346\225\260", nullptr));
        label_SendCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257\345\217\221\351\200\201\351\227\264\351\232\224(ms)", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\221\351\200\201\346\266\210\350\200\227\346\227\266\351\227\264", nullptr));
        ButtonLink->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        ButtonStopSend->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        push_SendLoop->setText(QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        ButtonopenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\230\276\347\244\272", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\276\223\345\205\245", nullptr));
        radioSendHex->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        ButtonSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        PushStopSend->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\345\217\221\351\200\201", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
