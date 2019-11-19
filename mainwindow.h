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
#include <QTextBrowser>
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
#include "logfilepathselection.h"
#include "ui_mainwindow.h"
const QString   BAUDTARE[]={"300","600","1200","2400","4800","9600","19200","38400","115200"};
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
    QString	Comname;
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
	 void openFile();
     bool getComparam(QSerialPort *setPort);
     bool setLable();
	 bool openComPort();
	 bool closeComPort();
	 bool comPortSendData();
     bool disPlaysendsinfo(const char *cmdstr,int length);
     bool disPlaysendPackSum(size_t length);
     bool setLoopSendTimeGap();
     bool changSendStrType(bool mode);
     bool scrollLast();
     bool openFilterSetWindow();
     bool setFilterParam(bool repeatIsOneDisplay,bool IsHex,QString DisPlayHead,
                         QString UnDisplayHead,QString DisPlayTail,QString UnDisPlayTail);
     bool setTimeStamp();
     void recviData(MainWindow* pwin);
     void disPlayRecvData(QString data);
     void clearDisPlayContent();
	 void startRecordLogToFile();
	 void stopRecordLogToFile();
signals:
     void emitComInfo(QSerialPort *ComPort, char *SendCmd ,int *SendLoopFlag);
     void emitSnedStr(const char *SendCmd,int length);
     void emitpackSum(int length);
     void emitUsetime(long long  timeuse);
     void emitRecviData(QString recvidata);
	 void emitOpenLogFileFail();

private:
	bool comSendDatathread();
	bool GetVisibleComPort();
	bool ConnectSlot();
	bool SendLoop();
	bool SendStop();
	bool ContextDisPlay(const QString &Discontext, unsigned int DisplayDirct, bool IsHex);
	void recordLogToFile();
	void openLogSavePathSetForm();
	
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
	LogFilePathSelection	*m_logFileSavePathGetDialog = {nullptr};
    QStringList				m_comportVisible;
	QString					m_logFileSavePath			= {QString()};
    QString					m_cmdfile;
	int						m_comParamChange			= { 0};
    QByteArray				m_btyeArray;
	QSerialPort				*m_qcomPort					= { nullptr };
	QSerialPortInfo			*m_visibleComPortInfor		= { nullptr };
	QTextCodec				*m_codec					= { nullptr };
	MessageFilter			*m_filterSetDialog			= { nullptr };//消息筛选类指针
	QToolButton				*m_toolButton				= { nullptr };
	QAction					*m_action					= { nullptr };
	int                      m_sendLoopFlag				= { 0 };
	byte                     *m_sendCmd					= { nullptr};
	size_t                   m_sendCount				= { 0 };
	bool                     m_sendIsRuning				= { false };
	std::thread              *m_sendthread				= { false };
	std::thread              *m_recviThread				= { false };
	std::thread              *m_recordLogFileThread		= { false };
	size_t                   m_sendPackSum				= { 0 };
	double					 m_sendNum					= { 0 };
	int                      m_sendTimeGap				= { 0 };
	bool                     m_sendHexMode				= { false };
	bool                     m_recviThreadRunFlag		= {false};
    /*消息筛选变量*/
	bool					 m_brepeatIsOneDisplay		= {false};
	bool					 m_bisHex					= {false};
	volatile bool            m_textIsChanged			= { false };
	volatile bool            m_recordRunFlag			= { false };
	volatile bool			 m_logPathIsVaild			= { false };
    QString					 m_strDisPlayHead;
    QString					 m_strUnDisplayHead;
    QString					 m_strDisPlayTail;
    QString					 m_strUnDisPlayTail;
	QString					 m_recordContent;
	bool					 m_bisAddtimeTimestamp		= { false };
	//本地串口类
	CSerialPort				 *m_nativeClassComport		= { nullptr };
	Comparaminit			 m_nativeComportParam;

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
