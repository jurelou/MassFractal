#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QString>
#include <iostream>

#include "FractalWidget.h"

class QComboBox;
class QFontComboBox;
class QGroupBox;
class QMenu;
class QMenuBar;
class QLabel;
class QLineEdit;
class QTextEdit;

class MainWindow : public QDialog
{
Q_OBJECT
public:
	MainWindow();

public slots:

private:
	void createMenu();
	void createHorizontalGroupBox();
void createGridGroupBox();
	enum { 
		NumGridRows = 2,
		NumButtons = 2
	};
	QMenuBar *menuBar;
	QGroupBox *horizontalGroupBox;
	QPushButton *buttons[NumButtons];
	QMenu *fileMenu;
	QAction *exitAction;
	QGroupBox *gridGroupBox;
	QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QTextEdit *smallEditor;

};

#endif