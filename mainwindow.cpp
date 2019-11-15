#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_cmdfile(""),
    m_qcomPort(nullptr),
	m_visibleComPortInfor(new QSerialPortInfo),
    m_btyeArray(""),
    m_sendLoopFlag(0),
    m_psendCmd(nullptr),
    m_sendCount(0),
    m_sendIsRuning(false),
    m_sendthread(nullptr),
    m_sendPackSum(0),
    m_sendNum(0.0),
    m_sendTimeGap(0),
    m_sendHexMode(false),
    m_filterSetDialog(nullptr),
    m_brepeatIsOneDisplay(false),
    m_bisHex(false),
    m_bisAddtimeTimestamp(false),
    m_recviThread(nullptr),
    m_recviDataArray(nullptr),
    m_recviThreadRunFlag(false),
    m_nativeClassComport(nullptr),
    m_toolButton(nullptr),
    m_action(nullptr)
{
    m_psendCmd = new byte[9];
    m_recviDataArray = new char[1024];
    memset(m_recviDataArray,0,1024);
    m_qcomPort = new QSerialPort;
    memset(m_psendCmd,0,9);
    m_psendCmd[0] = 0xA7;
    m_psendCmd[8] = 0xA8;
    m_sendNum = 0.001;
    m_filterSetDialog = new MessageFilter(this);
    m_filterSetDialog->hide();
    m_filterSetDialog->setWindowTitle(tr("filter set"));
    ui->setupUi(this);
    Comparaminit();
    GetComparaminit();
    SetLable();
	ConnectSlot();
    ui->Line_SendTimeGap->setText("10");
    SetSendGap();
    if(ui->radioSendHex->isChecked())
    {
        m_sendHexMode = true;
    }
    m_toolButton = new QToolButton(this);
    m_toolButton->setText(tr("clear set"));
    QMenu *ptoolmeu = new QMenu(this);
    m_action = new QAction(this);
    m_action->setText(tr("clear display area"));
    ptoolmeu->addAction(m_action);
    m_toolButton->setMenu(ptoolmeu);
    m_toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(m_toolButton);
    m_nativeClassComport =  new CSerialPort;
    GetComparamSetNative();
    ui->Cmddisplay->setReadOnly(true);
    m_recviThreadRunFlag = true;
    m_recviThread = new std::thread(&MainWindow::Recvidata,this,this);
}

MainWindow::~MainWindow()
{
  
	delete ui;
    delete[] m_psendCmd;
    if(m_sendthread!=nullptr)
    {
        if(m_sendthread->joinable())
        {
            m_sendthread->join();
            delete m_sendthread;
        }
    }
    m_recviThreadRunFlag =false;
    if(m_recviThread !=nullptr)
    {
        if(m_recviThread->joinable())
        {
            m_recviThread->join();
            delete m_recviThread;

        }
    }
    delete m_nativeClassComport;
    delete[] m_recviDataArray;
    delete[] m_psendCmd;
    delete m_filterSetDialog;
    delete m_toolButton;

}
bool MainWindow::OpenCom()
{
    GetComparamSetNative();
    if(!m_nativeClassComport->InitPort(m_nativeComportParam.Comname.right(1).toInt(),m_nativeComportParam.ComBaudRate,
                                             m_nativeComportParam.ComDataBit,m_nativeComportParam.ComStopBit,
                                             m_nativeComportParam.ComCheckway))
    {

                QMessageBox::StandardButton reply;
                 reply = QMessageBox::information(this, tr("串口打开失败"),tr("串口打开失败"),reply);
                 if (reply == QMessageBox::Ok)
                    return false;
                return false;

    }
	ui->ButtonLink->setEnabled(false);
    return true;
}
bool MainWindow::CloseComPort()
{
    m_sendLoopFlag = false;
    m_nativeClassComport->ClosePort();
	ui->ButtonLink->setEnabled(true);
	return true;
}
bool MainWindow::ComSendDatathread( )
{
    QSerialPort *SendLoop  = new QSerialPort(this);
    GetComparam(SendLoop);
    if(!SendLoop->open(QIODevice::ReadWrite))
    {
        delete SendLoop;
        return false;

    }
    std::string sendstr;
    if(SendLoop->isOpen())
    {
        while(m_sendLoopFlag)
        {

            if (SendLoop->isWritable())
            {
                 SendCmd();
                 int i = SendLoop->write((const char*)m_psendCmd, 9);
                 SendLoop->waitForBytesWritten(25);
                 m_sendPackSum++;
                 emitpackSum(m_sendPackSum);
                 std::this_thread::sleep_for(std::chrono::milliseconds(m_sendTimeGap));
            }
        }
    }
    SendLoop->close();
    delete SendLoop;
    return true;

}
bool MainWindow::ComSendData()
{

    std::string  SendTextstd;
    if( m_nativeClassComport ->IsOpen())
    {
        QString  SendText  = ui->SendTextEdit->toPlainText();
        if( m_sendHexMode )
        {
            SendText = SendText.trimmed();
            if(!SendText.contains(" ", Qt::CaseInsensitive))
            {
                int size = SendText.size();
                for(int i  = 2,j=0;i<size;i+=2)
                {
                    SendText.insert(i+j," ");
                    j++;
                }
            }
            QByteArray SendTextArray =  hexStringtoByteArray(SendText);
            SendTextstd =  SendTextArray.toStdString();
        }
        else
         {
            SendTextstd = SendText.toStdString();
        }

        bool completekey;
        m_nativeClassComport->WriteData((const char*)(SendTextstd.c_str()), SendTextstd.length(),completekey,0);
        ui->label_SendCount->setText(QString::number(m_sendPackSum));
        ContextDisPlay(SendText,1,m_sendHexMode);
    }
    else
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this, tr("提示"),tr("请先打开串口"),reply);
        if (reply == QMessageBox::Ok)
            return false;
        return false;
    }
    return true;
}
bool MainWindow::DisPlaysendsinfo(const char *cmdstr, int length)
{
      std::string dispstr = HexToHexStr((const char*)(m_psendCmd),9);
      ui->Cmddisplay->insertPlainText(dispstr.c_str());
      return true;

}

bool MainWindow::DisPlaysendPackSum(size_t length)
{

    ui->label_SendCount->setText(QString::number(length));
    return true;
}
bool MainWindow::SetSendGap()
{

     m_sendTimeGap = ui->Line_SendTimeGap->text().toInt();
     return true;

}
bool MainWindow::DisplayuseTime(long long timeuse)
{
    ui->Line_UseTime->setText(QString::number(timeuse));
    return true;

}
bool MainWindow::ChangSendStrType(bool mode)
{
    m_sendHexMode = mode;
    return true;
}
bool MainWindow::scrolllast()
{
     QTextCursor cursor = ui->Cmddisplay->textCursor();
      cursor.movePosition(QTextCursor::End);
      ui->Cmddisplay->setTextCursor(cursor);
      return true;
}
bool MainWindow::OpenFilterSetWindow()
{
    m_filterSetDialog->open();
	return true;
}
bool MainWindow::SetFilterParam(bool repeatIsOneDisplay, bool IsHex, QString DisPlayHead, QString UnDisplayHead, QString DisPlayTail, QString UnDisPlayTail)
{
    m_brepeatIsOneDisplay = repeatIsOneDisplay;
    m_bisHex = IsHex;
    m_strDisPlayHead = DisPlayHead;
    m_strUnDisplayHead = UnDisplayHead;
    m_strDisPlayTail  = DisPlayTail;
    m_strUnDisPlayTail = UnDisPlayTail;
    return true;
}
bool MainWindow::SetTimestamp()
{
    if(ui->checkBoxRecordTime->isChecked())
    {
         m_bisAddtimeTimestamp =true;
    }
    else
    {
         m_bisAddtimeTimestamp =false;
    }
    return true;
}

void MainWindow::Recvidata(MainWindow *pwin)
{
        while(m_recviThreadRunFlag)
        {
            if(m_nativeClassComport->IsOpen()&&m_nativeClassComport->GetBytesInCOM()>0)
            {
                    unsigned long   nReadlength = 1024;
                    memset(m_recviDataArray,0,1024);
                    if(m_nativeClassComport->ReadComPort(m_recviDataArray,nReadlength))
                    {
                        QString recvidata(m_recviDataArray);
                        emitRecviData(recvidata);
                    }
            }
        }
}

void MainWindow::DisPlayRecvData(QString data)
{
    ui->Cmddisplay->append(data);

}
void MainWindow::clearDisPlayContent()
{
    ui->Cmddisplay->clear();
}
bool MainWindow::GetComparaminit()
{
	
	GetVisibleComPort();
    for(int  i = 0 ;i< m_ComportVisible.length();++i)
    {
        ui->COMPort->addItem(m_ComportVisible[i]);
    }
    for(int  i= 0 ; i<=7;++i)
    {
        ui->BuadRate->addItem(BAUDTARE[i]);
    }
    for(int i  = 0 ; i< 4 ;++i)
    {
        ui->DataBit->addItem(DATABIT[i]);
    }
    for(int i  = 0 ; i< 5 ;++i)
    {
        ui->CheckBit->addItem(CHECKWAY[i]);
    }
    for(int i  = 0 ; i<3  ;++i)
    {
        ui->StopBit->addItem(STOPBIT[i]);
    }
    for(int i  = 0 ; i< 3 ;++i)
    {
        ui->StreamCtrl->addItem(STREAMCTRL[i]);
    }
    ui->COMPort->setCurrentIndex(0);
    ui->BuadRate->setCurrentIndex(5);
    ui->DataBit->setCurrentIndex(3);
    ui->StopBit->setCurrentIndex(0);
	ui->radioHex->setChecked(true);
    return true;


}

bool MainWindow::GetComparamSetNative()
{

    m_nativeComportParam.Comname = ui->COMPort->currentText();
    m_nativeComportParam.ComBaudRate = ui->BuadRate->currentText().toInt();
    m_nativeComportParam.ComDataBit =  ui->DataBit->currentText().toInt();
    m_nativeComportParam.ComStopBit = ui->StopBit->currentText().toInt();
    m_nativeComportParam.ComCheckway = ui->CheckBit->currentText().toInt();
//    int Databit  = ui->DataBit->currentText().toInt();
//    int Stopbit = ui->StopBit->currentText().toInt();
//    int checkway = ui->CheckBit->currentText().toInt();
//    int StreamCtrl = ui->StreamCtrl->currentText().toInt();
    return true;



}
void MainWindow::on_ButtonopenFile_clicked()
{

    ui->Cmddisplay->clear();
    m_cmdfile.clear();
    QString windowcaption;
    windowcaption= m_codec->toUnicode("打开命令文件");
    QString file_name = QFileDialog::getOpenFileName(this,windowcaption,".","*.txt");
    qDebug()<<file_name;
    QFile cmdfile(file_name);
    QTextStream filein(&cmdfile);
    if (!cmdfile.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
    QString Line;
	QString StrNotSpace;
	QString DisplayStr;
    Line = filein.readLine();
    while(!Line.isNull())
    {

        Line = filein.readLine();
		//去除空白字符
		for (int  i = 0; i < Line.length(); i++)
		{
			if (" "!=Line[i])
			{
				StrNotSpace = StrNotSpace + Line[i];
			}
		}
        m_cmdfile  += StrNotSpace + "\r\n";
    }
    ui->Cmddisplay->setPlainText(m_cmdfile);
    qDebug()<<m_cmdfile;
}

bool MainWindow::GetComparam(QSerialPort *SetPort)
{	
        QString  PortName = ui->COMPort->currentText();
        int BuadRate = ui->BuadRate->currentText().toInt();
        int Databit  = ui->DataBit->currentText().toInt();
        int Stopbit = ui->StopBit->currentText().toInt();
        int checkway = ui->CheckBit->currentText().toInt();
        int StreamCtrl = ui->StreamCtrl->currentText().toInt();
        SetPort->setPortName(PortName);
        SetPort->setBaudRate(BuadRate);
        SetPort->setDataBits(QSerialPort::DataBits(Databit));
        SetPort->setStopBits(QSerialPort::StopBits(Stopbit));//此处如果停止位在1.5位时会有问题
        SetPort->setParity(QSerialPort::EvenParity);
        SetPort->setDataErrorPolicy(QSerialPort::DataErrorPolicy(checkway));
        SetPort->setFlowControl(QSerialPort::FlowControl(StreamCtrl));
        return false;

}

bool MainWindow::SetLable()
{
        return true;
}
bool MainWindow::ConnectSlot()
{
	
	connect(ui->ButtonLink,&QPushButton::clicked,this,&MainWindow::OpenCom);
	connect(ui->ButtonStopSend, &QPushButton::clicked, this, &MainWindow::CloseComPort);
	connect(ui->ButtonSend, &QPushButton::clicked, this, &MainWindow::ComSendData);
    connect(ui->push_SendLoop, &QPushButton::clicked, this, &MainWindow::SendLoop);
    connect(ui->PushStopSend, &QPushButton::clicked, this, &MainWindow::SendStop);
    connect(this,SIGNAL(emitpackSum(size_t)),this,SLOT(DisPlaysendPackSum(size_t)));
    connect(this,SIGNAL(emitSnedStr(const char*,int)),this,SLOT(DisPlaysendsinfo(const char*,int)),Qt::DirectConnection);
    connect(this->ui->Line_SendTimeGap,&QLineEdit::textChanged,this,&MainWindow::SetSendGap);
    connect(this,&MainWindow::emitUsetime,this,&MainWindow::DisplayuseTime);
    connect(this->ui->radioSendHex,&QRadioButton::toggled,this,&MainWindow::ChangSendStrType);
    connect(this->ui->Cmddisplay,&QTextEdit::textChanged,this,&MainWindow::scrolllast);
    connect(this->ui->MessageFilter,&QPushButton::clicked,this,&MainWindow::OpenFilterSetWindow);
    connect(this->m_filterSetDialog,&MessageFilter::SetFilterOption,this,&MainWindow::SetFilterParam);
    connect(this->ui->checkBoxRecordTime,&QRadioButton::toggled,this,&MainWindow::SetTimestamp);
    connect(this, &MainWindow::emitRecviData,this, &MainWindow::DisPlayRecvData);
    connect(this->m_action,&QAction::triggered,this,&MainWindow::clearDisPlayContent);
    connect(this->ui->mainToolBar,&QToolBar::actionTriggered,this,&MainWindow::clearDisPlayContent);
    return true;
}
bool MainWindow::SendCmd()
{

    char *str = nullptr;
    unsigned char Max[1] = {0x99};
    std::string CheckNUm;
    if(m_psendCmd[3]<Max[0])
    {
        SetSendNum(m_psendCmd,3);
    }
    else
    {
        m_psendCmd[3] = 0x00 ;
        if(m_psendCmd[2]<Max[0])
        {
            SetSendNum(m_psendCmd,2);
        }
        else
        {
            m_psendCmd[2] = 0x00;
            if(m_psendCmd[1]<Max[0])
            {
                SetSendNum(m_psendCmd,1);
            }
            else
            {
                 m_psendCmd[1]  = 0x00;
                 m_psendCmd[2]  = 0x00;
                 m_psendCmd[3]  = 0x00;
            }
        }
    }

    if(m_psendCmd[6]< Max[0])
    {
        SetSendNum(m_psendCmd,6);
    }
    else
    {
        m_psendCmd[6] = 0x00 ;
        if(m_psendCmd[5]<Max[0])
        {
            SetSendNum(m_psendCmd,5);
        }
        else
        {
            m_psendCmd[5] = 0x00;
            if(m_psendCmd[4]<Max[0])
            {
                SetSendNum(m_psendCmd,4);
            }
            else
            {
                 m_psendCmd[4]  = 0x00;
                 m_psendCmd[5]  = 0x00;
                 m_psendCmd[6]  = 0x00;
            }
        }
    }
    CheckNUm = "0x"+ std::to_string(CalculateSumCheck(m_psendCmd,1));
    m_psendCmd[7] =   strtol(CheckNUm.c_str(), &str, 16);
    return true;

}

bool MainWindow::SendLoop()
{

     memset(m_psendCmd,0,9);
     m_psendCmd[0] = 0xA7;
     m_psendCmd[8] = 0xA8;
     ui->label_SendCount->clear();
     m_sendLoopFlag =true;
     if( m_sendthread == nullptr)
     {  if(m_qcomPort->isOpen())
         {
             m_qcomPort->close();
         }
         m_sendthread = new std::thread(&MainWindow::ComSendDatathread,this);
         ui->push_SendLoop->setEnabled(false);
     }
     else
     {
         SendStop();
         if(m_qcomPort->isOpen())
         {
            m_qcomPort->close();
         }
         m_sendthread = new std::thread(&MainWindow::ComSendDatathread,this);
         ui->push_SendLoop->setEnabled(false);

     }
     return true;

}

bool MainWindow::SendStop()
{
    m_sendLoopFlag =false;
    if(m_sendthread!=nullptr)
    {
        if(m_sendthread->joinable())
        {
            m_sendthread->join();
            delete m_sendthread;
            m_sendthread = nullptr;
        }
    }
    ui->push_SendLoop->setEnabled(true);
    if(m_qcomPort->isOpen())
    {
       m_qcomPort->open(QIODevice::ReadWrite);
    }
    return true;
}

bool MainWindow::ContextDisPlay(const QString &Discontext,unsigned int DisplayDirct,bool IsHex )
{
    QString  DisText;
    QString nowtime;
    if(this->m_bisAddtimeTimestamp)
    {
        QDateTime now = QDateTime::currentDateTime();
        nowtime = now.toString("hh:mm:ss.zzz");
        DisText  = DisText +"time:"+nowtime+"--";
    }
    //Send
    if(DisplayDirct == 1)
    {
          DisText  = DisText + QObject::tr("发送: ") +Discontext;
    }
    //Recvi
    else if(DisplayDirct == 0)
    {
          DisText  = DisText + QObject::tr("接收: ")+Discontext;
    }
    else
    {
        return false;
    }
    if(IsHex)
    {
        DisText+=" (Hex)";
    }
    else
    {
        DisText+=" (ASCII)";
    }
    ui->Cmddisplay->append(DisText);

}
unsigned int   MainWindow::CalculateSumCheck(  byte *ProtocolStore,   uint32_t ProtocolHead)
{
    int SunCheckRes = 0 ;
    for(int i = 1 ;i<7;++i )
    {
        SunCheckRes  += (BCDtoDec(&ProtocolStore[ProtocolHead-1+i],1));
    }
    SunCheckRes = SunCheckRes%100;
    return SunCheckRes;
}
bool MainWindow::StrToASCIIStr(std::string & asciistr)
{	

	std::string result = "0x";
	std::string tmp;
	std::stringstream ss;
	for (int i = 0; i<asciistr.size(); i++)
	{
		ss << std::hex << int(asciistr[i]) << std::endl;
		ss >> tmp;
		result += tmp;
	}
	return true;
}
bool MainWindow::StrToHexstr(std::string & asciistr)
{
	using BYTE = unsigned int;
	std::vector<BYTE> bytearry;
	std::string HexFlags = "0x";
	std::string result;
	std::string resultret;
	std::string tmp;
	std::stringstream ss;
	char *Hexstr = nullptr;
	for (size_t i = 0; i < asciistr.length()-2; i=i+2)
	{
		std::string substr;
		substr = asciistr.substr(i,2);
		BYTE k = (unsigned char)strtol(substr.c_str(), &Hexstr, 16);
		bytearry.push_back(k);
	}
    return true;
}

std::string MainWindow::HexToHexStr(const char *hex, int length)
{
    std::string Ret;
    for(int i = 0; i<length;++i)
    {
        int k  = atoi(hex++);
        Ret= Ret + " 0x" +  QString::number(k,16).toStdString();
    }
    return Ret;

}

bool MainWindow::SetSendNum(byte *cmd, int nIndex)
{
    byte tem[1]={0};
    if((cmd[nIndex]&0x0f)<0x09)
    {
          cmd[nIndex] += 0x01;
    }
    else
    {
        cmd[nIndex] = cmd[nIndex]&0xf0;//
        if(((cmd[nIndex]>>4)&0xf0)<0x09)
        {
            tem[0] = (cmd[nIndex]>>4)+0x01;
            cmd[nIndex] = (tem[0]<<4);
        }
    }

    return true;
}
QByteArray MainWindow::hexStringtoByteArray(QString hex)
{
        QByteArray ret;
        hex=hex.trimmed();

        QStringList sl=hex.split(" ");
        foreach(QString s,sl)
        {
            if(!s.isEmpty())
                ret.append((char)s.toInt(0,16)&0xFF);
        }
        return ret;
}
bool MainWindow::GetVisibleComPort()
{
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		QString ComportInfo;
		ComportInfo =   info.portName();
		m_ComportVisible.append(ComportInfo);
	}
	return true;
	
}
