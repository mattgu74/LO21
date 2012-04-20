#include <QTextStream>
#include <cstdio>
#include "element.h"
#include "mymainwindow.h"

#include <QApplication>
#include <QtGui>

int main( int argc, char ** argv) {
	QApplication mainApp(argc, argv);
	MyMainWindow win;
	win.show();
	return mainApp.exec();
}
