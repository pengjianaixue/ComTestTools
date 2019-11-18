#include "logfilepathselection.h"

LogFilePathSelection::LogFilePathSelection(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(this->ui.lineEdit_filepath, &QLineEdit::textChanged, this, [&] {m_logFileSavePath = this->ui.lineEdit_filepath->text(); emit emitFilePath(m_logFileSavePath);});
	connect(this->ui.pushButton_opendir, &QPushButton::clicked, this, &LogFilePathSelection::openGetFilePathDialog);
}

LogFilePathSelection::~LogFilePathSelection()
{


}

const QString &LogFilePathSelection::getPath() const
{
	return m_logFileSavePath;
}

void LogFilePathSelection::emitTheFilePath()
{

}

void LogFilePathSelection::openGetFilePathDialog()
{
	m_logFileSavePath = QFileDialog::getExistingDirectory(this, QApplication::translate("LogFilePathSelection", "\346\227\245\345\277\227\345\255\230\345\202\250\350\267\257\345\276\204\351\200\211\346\213\251", Q_NULLPTR)); // 日志路径选择 Chinese language hard code 
	QDateTime now = QDateTime::currentDateTime();
	QString	  logFileName = "/log-" +  now.toString("hh:mm:ss.zzz") + ".txt";
	this->ui.lineEdit_filepath->setText(m_logFileSavePath + "/log.txt");
	
}
