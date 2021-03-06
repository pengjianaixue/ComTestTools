#ifndef MESSAGEFILTER_H
#define MESSAGEFILTER_H

#include <QDialog>

namespace Ui {
class MessageFilter;
}

class MessageFilter : public QDialog
{
    Q_OBJECT

public:
    explicit MessageFilter(QWidget *parent = 0);
    ~MessageFilter();
signals:
    bool SetFilterOption(bool repeatIsOneDisplay,bool  IsHex,QString DisPlayHead,
                                    QString UnDisplayHead,QString  DisPlayTail,QString UnDisPlayTail );

private slots:
    //保存按钮槽函数
    void save();
      //关闭按钮槽函数
    void close();

private:
    Ui::MessageFilter *ui;
};

#endif // MESSAGEFILTER_H
