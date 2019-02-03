#include <QApplication>

#include "mainWindow.h"
 
int main(int argv, char **args)
{
	QApplication app(argv, args);
	MainWindow mainWin;
    mainWin.show();
	return app.exec();
}