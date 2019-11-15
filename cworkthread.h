#ifndef CWORKTHREAD_H
#define CWORKTHREAD_H
#include <QMainWindow>
#include <QObject>
#include <QThread>
#include <QSerialPort>
// QSerialPort         *m_ComPort  =new QSerialPort;
class CWorkThread :public QThread
{
public:
    CWorkThread();
 protected:
    void run();
 public slots:
    int GetComParam(QSerialPort *ComPort, char *SendCmd ,int *SendLoopFlag);

private:
    QSerialPort *m_ComPort;
    char *m_SendCmd;
    int *m_SendLoopFlag;

};
#endif // CWORKTHREAD_H
