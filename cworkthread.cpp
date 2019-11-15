#include "cworkthread.h"

CWorkThread::CWorkThread()
{

}

void CWorkThread::run()
{
    if(m_ComPort == nullptr||m_SendLoopFlag==nullptr||m_SendCmd==nullptr)return ;
    if(m_ComPort->isOpen())
    {
        while(*m_SendLoopFlag)
        {
            if (m_ComPort->isWritable())
            {
                int i = m_ComPort->write((const char*)m_SendCmd, 9);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    }
}

int CWorkThread::GetComParam(QSerialPort *ComPort, char *SendCmd , int *SendLoopFlag)
{
    m_ComPort = ComPort;
    m_SendCmd = SendCmd;
    m_SendLoopFlag = SendLoopFlag;
}
