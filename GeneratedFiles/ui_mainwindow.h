/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openComportAction;
    QAction *startRecordAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QWidget *widget_comparamset;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *formGroupBox;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QComboBox *COMPort;
    QComboBox *BuadRate;
    QComboBox *DataBit;
    QComboBox *StopBit;
    QComboBox *CheckBit;
    QComboBox *StreamCtrl;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *RadioAscii;
    QCheckBox *checkBoxRecordTime;
    QVBoxLayout *verticalLayout_11;
    QRadioButton *radioHex;
    QPushButton *MessageFilter;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_SendCount;
    QLineEdit *Line_SendTimeGap;
    QPushButton *ButtonLink;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_cleandiaplay;
    QTextBrowser *textbrowse_cmddisplay;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QRadioButton *radioSendHex;
    QTextEdit *SendTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSend;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PushStopSend;
    QPushButton *push_SendLoop;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(798, 604);
        openComportAction = new QAction(MainWindow);
        openComportAction->setObjectName(QString::fromUtf8("openComportAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/icon/resource/serial-port-on.png"), QSize(), QIcon::Normal, QIcon::Off);
        openComportAction->setIcon(icon);
        startRecordAction = new QAction(MainWindow);
        startRecordAction->setObjectName(QString::fromUtf8("startRecordAction"));
        startRecordAction->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rc/icon/resource/record-off.png"), QSize(), QIcon::Normal, QIcon::Off);
        startRecordAction->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        widget_comparamset = new QWidget(centralWidget);
        widget_comparamset->setObjectName(QString::fromUtf8("widget_comparamset"));
        verticalLayout_6 = new QVBoxLayout(widget_comparamset);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formGroupBox = new QGroupBox(widget_comparamset);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formGroupBox->sizePolicy().hasHeightForWidth());
        formGroupBox->setSizePolicy(sizePolicy);
        formGroupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_12 = new QVBoxLayout(formGroupBox);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(formGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(formGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(formGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(formGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(formGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(formGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        COMPort = new QComboBox(formGroupBox);
        COMPort->setObjectName(QString::fromUtf8("COMPort"));

        verticalLayout_4->addWidget(COMPort);

        BuadRate = new QComboBox(formGroupBox);
        BuadRate->setObjectName(QString::fromUtf8("BuadRate"));

        verticalLayout_4->addWidget(BuadRate);

        DataBit = new QComboBox(formGroupBox);
        DataBit->setObjectName(QString::fromUtf8("DataBit"));

        verticalLayout_4->addWidget(DataBit);

        StopBit = new QComboBox(formGroupBox);
        StopBit->setObjectName(QString::fromUtf8("StopBit"));

        verticalLayout_4->addWidget(StopBit);

        CheckBit = new QComboBox(formGroupBox);
        CheckBit->setObjectName(QString::fromUtf8("CheckBit"));

        verticalLayout_4->addWidget(CheckBit);

        StreamCtrl = new QComboBox(formGroupBox);
        StreamCtrl->setObjectName(QString::fromUtf8("StreamCtrl"));

        verticalLayout_4->addWidget(StreamCtrl);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 6);

        verticalLayout_12->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        RadioAscii = new QRadioButton(formGroupBox);
        RadioAscii->setObjectName(QString::fromUtf8("RadioAscii"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RadioAscii->sizePolicy().hasHeightForWidth());
        RadioAscii->setSizePolicy(sizePolicy1);
        RadioAscii->setMinimumSize(QSize(96, 0));

        verticalLayout_5->addWidget(RadioAscii);

        checkBoxRecordTime = new QCheckBox(formGroupBox);
        checkBoxRecordTime->setObjectName(QString::fromUtf8("checkBoxRecordTime"));
        sizePolicy1.setHeightForWidth(checkBoxRecordTime->sizePolicy().hasHeightForWidth());
        checkBoxRecordTime->setSizePolicy(sizePolicy1);
        checkBoxRecordTime->setMinimumSize(QSize(96, 0));

        verticalLayout_5->addWidget(checkBoxRecordTime);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        radioHex = new QRadioButton(formGroupBox);
        radioHex->setObjectName(QString::fromUtf8("radioHex"));
        radioHex->setMinimumSize(QSize(50, 0));

        verticalLayout_11->addWidget(radioHex);

        MessageFilter = new QPushButton(formGroupBox);
        MessageFilter->setObjectName(QString::fromUtf8("MessageFilter"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MessageFilter->sizePolicy().hasHeightForWidth());
        MessageFilter->setSizePolicy(sizePolicy2);
        MessageFilter->setMinimumSize(QSize(60, 0));

        verticalLayout_11->addWidget(MessageFilter);


        horizontalLayout_7->addLayout(verticalLayout_11);


        verticalLayout_12->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_7 = new QLabel(formGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 20));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(formGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_SendCount = new QLabel(formGroupBox);
        label_SendCount->setObjectName(QString::fromUtf8("label_SendCount"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_SendCount->sizePolicy().hasHeightForWidth());
        label_SendCount->setSizePolicy(sizePolicy3);
        label_SendCount->setMinimumSize(QSize(0, 20));
        label_SendCount->setMaximumSize(QSize(60, 16777215));

        verticalLayout_2->addWidget(label_SendCount);

        Line_SendTimeGap = new QLineEdit(formGroupBox);
        Line_SendTimeGap->setObjectName(QString::fromUtf8("Line_SendTimeGap"));
        Line_SendTimeGap->setMaximumSize(QSize(60, 16777215));

        verticalLayout_2->addWidget(Line_SendTimeGap);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_12->addLayout(horizontalLayout_6);

        verticalLayout_12->setStretch(0, 7);
        verticalLayout_12->setStretch(1, 1);
        verticalLayout_12->setStretch(2, 2);

        verticalLayout_6->addWidget(formGroupBox);

        ButtonLink = new QPushButton(widget_comparamset);
        ButtonLink->setObjectName(QString::fromUtf8("ButtonLink"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ButtonLink->sizePolicy().hasHeightForWidth());
        ButtonLink->setSizePolicy(sizePolicy4);
        ButtonLink->setMaximumSize(QSize(180, 16777215));
        ButtonLink->setLayoutDirection(Qt::LeftToRight);
        ButtonLink->setStyleSheet(QString::fromUtf8("QPushButton{ color: rgb(255, 0, 0)}"));
        ButtonLink->setIcon(icon);

        verticalLayout_6->addWidget(ButtonLink);


        horizontalLayout_10->addWidget(widget_comparamset);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        pushButton_cleandiaplay = new QPushButton(centralWidget);
        pushButton_cleandiaplay->setObjectName(QString::fromUtf8("pushButton_cleandiaplay"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rc/icon/resource/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_cleandiaplay->setIcon(icon2);

        horizontalLayout_9->addWidget(pushButton_cleandiaplay);


        verticalLayout_8->addLayout(horizontalLayout_9);

        textbrowse_cmddisplay = new QTextBrowser(centralWidget);
        textbrowse_cmddisplay->setObjectName(QString::fromUtf8("textbrowse_cmddisplay"));

        verticalLayout_8->addWidget(textbrowse_cmddisplay);


        verticalLayout_10->addLayout(verticalLayout_8);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_10);

        radioSendHex = new QRadioButton(groupBox);
        radioSendHex->setObjectName(QString::fromUtf8("radioSendHex"));

        horizontalLayout->addWidget(radioSendHex);


        verticalLayout_9->addLayout(horizontalLayout);

        SendTextEdit = new QTextEdit(groupBox);
        SendTextEdit->setObjectName(QString::fromUtf8("SendTextEdit"));
        SendTextEdit->setMaximumSize(QSize(16777215, 30));

        verticalLayout_9->addWidget(SendTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        ButtonSend = new QPushButton(groupBox);
        ButtonSend->setObjectName(QString::fromUtf8("ButtonSend"));
        sizePolicy2.setHeightForWidth(ButtonSend->sizePolicy().hasHeightForWidth());
        ButtonSend->setSizePolicy(sizePolicy2);
        ButtonSend->setAutoRepeat(true);

        horizontalLayout_3->addWidget(ButtonSend);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        PushStopSend = new QPushButton(groupBox);
        PushStopSend->setObjectName(QString::fromUtf8("PushStopSend"));
        sizePolicy2.setHeightForWidth(PushStopSend->sizePolicy().hasHeightForWidth());
        PushStopSend->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(PushStopSend);

        push_SendLoop = new QPushButton(groupBox);
        push_SendLoop->setObjectName(QString::fromUtf8("push_SendLoop"));
        sizePolicy2.setHeightForWidth(push_SendLoop->sizePolicy().hasHeightForWidth());
        push_SendLoop->setSizePolicy(sizePolicy2);
        push_SendLoop->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_2->addWidget(push_SendLoop);


        verticalLayout_9->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);


        verticalLayout_10->addWidget(groupBox);

        verticalLayout_10->setStretch(0, 7);
        verticalLayout_10->setStretch(1, 3);

        horizontalLayout_10->addLayout(verticalLayout_10);

        horizontalLayout_10->setStretch(0, 2);
        horizontalLayout_10->setStretch(1, 8);

        gridLayout_2->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 798, 23));
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
        menu->addAction(openComportAction);
        menu->addAction(startRecordAction);
        mainToolBar->addAction(openComportAction);
        mainToolBar->addAction(startRecordAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        openComportAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        startRecordAction->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\260\345\275\225", nullptr));
        formGroupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247", nullptr));
        RadioAscii->setText(QApplication::translate("MainWindow", "Ascii", nullptr));
        checkBoxRecordTime->setText(QApplication::translate("MainWindow", "\350\256\260\345\275\225\346\227\266\351\227\264\346\210\263", nullptr));
        radioHex->setText(QApplication::translate("MainWindow", "Hex", nullptr));
        MessageFilter->setText(QApplication::translate("MainWindow", "\347\255\233\351\200\211\350\256\276\347\275\256", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\241\346\225\260", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\345\217\221\351\200\201\351\227\264\351\232\224(ms)", nullptr));
        label_SendCount->setText(QApplication::translate("MainWindow", "0", nullptr));
        ButtonLink->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\230\276\347\244\272", nullptr));
        pushButton_cleandiaplay->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\230\276\347\244\272", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272\345\237\237", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\276\223\345\205\245", nullptr));
        radioSendHex->setText(QApplication::translate("MainWindow", "Hex", nullptr));
        ButtonSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        PushStopSend->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        push_SendLoop->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
