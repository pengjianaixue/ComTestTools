#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <qtextcodec.h>
#include <qmessagebox.h>
#include <qerrormessage.h>
#include <string>
#include <sstream>
#include <thread>
#include <QThread>
#include <QMetaType>
#include <QDateTime>
#include <QToolButton>
#include <cmath>
#include "messagefilter.h"
#include "ComDevice.hpp"
namespace Ui {
	class MainWindow;
}
const QString   BAUDTARE[]={"300","600","1200","2400","4800","9600","19200","38400"};
const QString   DATABIT[]={"5","6","7","8"};
const QString   CHECKWAY[]={"NODE","EVEN","ODD","MARK","SPACE"};
const QString   STOPBIT[]={"1","1.5","2"};
const QString   STREAMCTRL[]={"NODE","RTS/CTS","XON/XOFF"};

using byte  =  unsigned char;
class MainWindow : public QMainWindow
{
    Q_OBJECT
struct  Comparaminit
{
    QString		Comname;
    int		ComBaudRate;
    int		ComDataBit;
    int		ComStopBit;
    int		ComCheckway;
    int		CommStreamCtrl;
    Comparaminit():Comname(""),
     ComBaudRate(9600),ComDataBit(8),
     ComStopBit(1),ComCheckway(0),
     CommStreamCtrl(0)
    { }

};

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool GetComparaminit();
    bool GetComparamSetNative();
private slots:
	 void on_ButtonopenFile_clicked();
     bool GetComparam(QSerialPort *SetPort);
     bool SetLable();
	 bool OpenCom();
	 bool CloseComPort();
	 bool ComSendData();
     bool DisPlaysendsinfo(const char *cmdstr,int length);
     bool DisPlaysendPackSum(size_t length);
     bool SetSendGap();
     bool DisplayuseTime(long long  timeuse );
     bool ChangSendStrType(bool mode);
     bool scrolllast();
     bool OpenFilterSetWindow();
     bool SetFilterParam(bool repeatIsOneDisplay,bool  IsHex,QString DisPlayHead,
                         QString UnDisplayHead,QString  DisPlayTail,QString UnDisPlayTail);
     bool SetTimestamp();
     void Recvidata(MainWindow* pwin);
     void DisPlayRecvData(QString data);
     void clearDisPlayContent();
signals:
     void emitComInfo(QSerialPort *ComPort, char *SendCmd ,int *SendLoopFlag);
     void emitSnedStr(const char *SendCmd,int length);
     void emitpackSum(int length);
     void emitUsetime(long long  timeuse);
     void emitRecviData(QString recvidata);

private:
    bool ComSendDatathread();
	bool GetVisibleComPort();
	bool ConnectSlot();
    bool  SendCmd();
    bool  SendLoop();
    bool SendStop();
    bool ContextDisPlay(const QString &Discontext, unsigned int DisplayDirct, bool IsHex);
	
public :
	static  bool StrToASCIIStr(std::string & asciistr);
    unsigned int CalculateSumCheck(byte *ProtocolStore,   uint32_t ProtocolHead);
	bool StrToHexstr(std::string & asciistr);
	template <typename T> static bool freemem(T *mem);
    static unsigned long  BCDtoDec(const byte *bcd, int length);
    static std::string    HexToHexStr(const char *hex,int length);
    static  bool SetSendNum(byte *cmd , int nIndex);
    QByteArray hexStringtoByteArray(QString hex);
private:
    Ui::MainWindow *ui;
 private:
    QStringList			m_ComportVisible;
    QString				m_cmdfile;
    int                 m_comParamChange;
    QByteArray			m_btyeArray;
    QSerialPort         *m_qcomPort;
    QSerialPortInfo     *m_visibleComPortInfor;
    QTextCodec			*m_codec;
    MessageFilter		*m_filterSetDialog;//消息筛选类指针
    QToolButton			*m_toolButton;
    QAction				*m_action;
private:
	int                      m_sendLoopFlag			= { 0 };
	byte                     *m_psendCmd			= { nullptr};
	size_t                   m_sendCount			= { 0 };
	bool                     m_sendIsRuning			= { false };
	std::thread              *m_sendthread			= { false };
	std::thread              *m_recviThread			= { false };
	size_t                   m_sendPackSum			= { 0 };
	double					 m_sendNum				= { 0 };
	int                      m_sendTimeGap			= { 0 };
	bool                     m_sendHexMode			= { false };
	char                     *m_recviDataArray		= {nullptr};
	bool                     m_recviThreadRunFlag	= {false};

    /*消息筛选变量*/
	bool            m_brepeatIsOneDisplay	= {false};
	bool            m_bisHex				= {false};
    QString         m_strDisPlayHead;
    QString         m_strUnDisplayHead;
    QString         m_strDisPlayTail;
    QString         m_strUnDisPlayTail;
	bool            m_bisAddtimeTimestamp = {false};
    //本地串口类
	CSerialPort     *m_nativeClassComport = {nullptr};
    Comparaminit    m_nativeComportParam;
};


template <typename T>  bool MainWindow::freemem(T *mem)
{	

	mem = static_cast<T>(mem);
	if (nullptr != mem)
	{
		delete mem;
		mem = nullptr;
    }
	return true;
}
inline unsigned long MainWindow::BCDtoDec(const  byte *bcd, int length)
{
    int tmp;
    unsigned long dec = 0;
    for (int i = 0; i < length; i++)
    {
        tmp = ((bcd[i] >> 4) & 0x0F) * 10 + (bcd[i] & 0x0F);
        dec += tmp * pow(100, length - 1 - i);
    }
    return dec;
}
  //Q_DECLARE_METATYPE(size_t)
#endif // MAINWINDOW_H
