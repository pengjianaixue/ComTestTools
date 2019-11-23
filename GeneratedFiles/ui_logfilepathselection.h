/********************************************************************************
** Form generated from reading UI file 'logfilepathselection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEPATHSELECTION_H
#define UI_LOGFILEPATHSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogFilePathSelection
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_filepath;
    QPushButton *pushButton_opendir;

    void setupUi(QDialog *LogFilePathSelection)
    {
        if (LogFilePathSelection->objectName().isEmpty())
            LogFilePathSelection->setObjectName(QString::fromUtf8("LogFilePathSelection"));
        LogFilePathSelection->setWindowModality(Qt::ApplicationModal);
        LogFilePathSelection->resize(357, 113);
        gridLayout = new QGridLayout(LogFilePathSelection);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_filepath = new QLineEdit(LogFilePathSelection);
        lineEdit_filepath->setObjectName(QString::fromUtf8("lineEdit_filepath"));

        gridLayout->addWidget(lineEdit_filepath, 0, 0, 1, 1);

        pushButton_opendir = new QPushButton(LogFilePathSelection);
        pushButton_opendir->setObjectName(QString::fromUtf8("pushButton_opendir"));

        gridLayout->addWidget(pushButton_opendir, 0, 1, 1, 1);


        retranslateUi(LogFilePathSelection);

        QMetaObject::connectSlotsByName(LogFilePathSelection);
    } // setupUi

    void retranslateUi(QDialog *LogFilePathSelection)
    {
        LogFilePathSelection->setWindowTitle(QApplication::translate("LogFilePathSelection", "\346\227\245\345\277\227\345\255\230\345\202\250\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        pushButton_opendir->setText(QApplication::translate("LogFilePathSelection", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogFilePathSelection: public Ui_LogFilePathSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEPATHSELECTION_H
