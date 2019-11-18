/********************************************************************************
** Form generated from reading UI file 'messagefilter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFILTER_H
#define UI_MESSAGEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MessageFilter
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QCheckBox *checkBoxDisOnce;
    QLabel *label_3;
    QRadioButton *radiohexFilter;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *EditMessagehead;
    QLabel *label_4;
    QLineEdit *EditUnDisplayHead;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *EditMessageTail;
    QLabel *label_5;
    QLineEdit *EditUnDisplayTail;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Save;
    QPushButton *Close;

    void setupUi(QDialog *MessageFilter)
    {
        if (MessageFilter->objectName().isEmpty())
            MessageFilter->setObjectName(QStringLiteral("MessageFilter"));
        MessageFilter->resize(445, 125);
        formLayout = new QFormLayout(MessageFilter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(MessageFilter);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        checkBoxDisOnce = new QCheckBox(MessageFilter);
        checkBoxDisOnce->setObjectName(QStringLiteral("checkBoxDisOnce"));

        horizontalLayout_3->addWidget(checkBoxDisOnce);

        label_3 = new QLabel(MessageFilter);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        radiohexFilter = new QRadioButton(MessageFilter);
        radiohexFilter->setObjectName(QStringLiteral("radiohexFilter"));

        horizontalLayout_3->addWidget(radiohexFilter);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MessageFilter);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        EditMessagehead = new QLineEdit(MessageFilter);
        EditMessagehead->setObjectName(QStringLiteral("EditMessagehead"));

        horizontalLayout->addWidget(EditMessagehead);

        label_4 = new QLabel(MessageFilter);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        EditUnDisplayHead = new QLineEdit(MessageFilter);
        EditUnDisplayHead->setObjectName(QStringLiteral("EditUnDisplayHead"));

        horizontalLayout->addWidget(EditUnDisplayHead);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(MessageFilter);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        EditMessageTail = new QLineEdit(MessageFilter);
        EditMessageTail->setObjectName(QStringLiteral("EditMessageTail"));

        horizontalLayout_2->addWidget(EditMessageTail);

        label_5 = new QLabel(MessageFilter);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        EditUnDisplayTail = new QLineEdit(MessageFilter);
        EditUnDisplayTail->setObjectName(QStringLiteral("EditUnDisplayTail"));

        horizontalLayout_2->addWidget(EditUnDisplayTail);


        verticalLayout->addLayout(horizontalLayout_2);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Save = new QPushButton(MessageFilter);
        Save->setObjectName(QStringLiteral("Save"));

        horizontalLayout_4->addWidget(Save);

        Close = new QPushButton(MessageFilter);
        Close->setObjectName(QStringLiteral("Close"));

        horizontalLayout_4->addWidget(Close);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_4);


        retranslateUi(MessageFilter);

        QMetaObject::connectSlotsByName(MessageFilter);
    } // setupUi

    void retranslateUi(QDialog *MessageFilter)
    {
        MessageFilter->setWindowTitle(QApplication::translate("MessageFilter", "\347\255\233\351\200\211\350\256\276\347\275\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("MessageFilter", "\351\207\215\345\244\215\346\266\210\346\201\257\345\217\252\346\230\276\347\244\272\344\270\200\346\254\241", Q_NULLPTR));
        checkBoxDisOnce->setText(QApplication::translate("MessageFilter", "CheckBox", Q_NULLPTR));
        label_3->setText(QApplication::translate("MessageFilter", "\345\215\201\345\205\255\350\277\233\345\210\266\347\255\233\351\200\211", Q_NULLPTR));
        radiohexFilter->setText(QApplication::translate("MessageFilter", "RadioButton", Q_NULLPTR));
        label->setText(QApplication::translate("MessageFilter", "\346\230\276\347\244\272\346\266\210\346\201\257\345\244\264", Q_NULLPTR));
        label_4->setText(QApplication::translate("MessageFilter", "\344\270\215\346\230\276\347\244\272\346\266\210\346\201\257\345\244\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("MessageFilter", "\346\230\276\347\244\272\346\266\210\346\201\257\345\260\276", Q_NULLPTR));
        label_5->setText(QApplication::translate("MessageFilter", "\344\270\215\346\230\276\347\244\272\346\266\210\346\201\257\345\260\276", Q_NULLPTR));
        Save->setText(QApplication::translate("MessageFilter", "\344\277\235\345\255\230", Q_NULLPTR));
        Close->setText(QApplication::translate("MessageFilter", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessageFilter: public Ui_MessageFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFILTER_H
