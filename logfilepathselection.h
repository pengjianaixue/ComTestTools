#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QDateTime>
#include <QTextCodec>
#include "ui_logfilepathselection.h"

class LogFilePathSelection : public QDialog
{
	Q_OBJECT

public:
	LogFilePathSelection(QWidget *parent = Q_NULLPTR);
	~LogFilePathSelection();
	const QString &getPath() const;
private slots:
	void openGetFilePathDialog();
	void emitTheFilePath();
signals:
	void emitFilePath(const QString &filePath);
private:
	Ui::LogFilePathSelection ui;
	QString			m_logFileSavePath;
};
