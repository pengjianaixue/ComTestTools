#include "messagefilter.h"
#include "ui_messagefilter.h"

MessageFilter::MessageFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageFilter)
{
    ui->setupUi(this);

}

MessageFilter::~MessageFilter()
{
    delete ui;
}
void MessageFilter::save()
{
    bool repeatIsOneDisplay  = ui->checkBoxDisOnce->isChecked();
    bool  IsHex = ui->radiohexFilter->isChecked();
    QString DisPlayHead = ui->EditMessagehead->text();
    QString UnDisplayHead = ui->EditUnDisplayHead->text();
    QString  DisPlayTail = ui->EditMessageTail->text();
    QString UnDisPlayTail = ui->EditUnDisplayTail->text();
    emit SetFilterOption(repeatIsOneDisplay,IsHex,DisPlayHead,UnDisplayHead,DisPlayTail,UnDisPlayTail);
}
void MessageFilter::close()
{
    this->close();
}
