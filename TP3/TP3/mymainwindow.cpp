#include "mymainwindow.h"
#include "mywidget.h"
#include <QtGui>

void MyMainWindow::about()
{
	QStatusBar *barreEtat = statusBar();
	barreEtat->showMessage("About");
	QMessageBox::information(this, "About", "Cet exercice est sympa !");
	barreEtat->clearMessage();
}

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
	QMenu *menuAnimation = menuBar()->addMenu("&Animation");
	QMenu *menuHelp = menuBar()->addMenu("&Help");

	QAction *actionPlay = new QAction("&Play", this);
	QAction *actionPause = new QAction("Pa&use", this);
	QAction *actionReset = new QAction("&Reset", this);
	QAction *actionQuit = new QAction("&Quit", this);

	menuAnimation->addAction(actionPlay);
	menuAnimation->addAction(actionPause);
	menuAnimation->addAction(actionReset);
	menuAnimation->addAction(actionQuit);

	QAction *actionAbout = new QAction("&About", this);
	menuHelp->addAction(actionAbout);

	QStatusBar *barreEtat = statusBar();
	barreEtat->showMessage("Done");

	MyWidget *mywidget = new MyWidget(this);
	setCentralWidget(mywidget);
	resize(800,600);

	connect(actionQuit,SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(actionAbout,SIGNAL(triggered()), this, SLOT(about()));
	// MYWIDGET SLOT
	connect(actionPlay,SIGNAL(triggered()), mywidget, SLOT(play()));
	connect(actionPause,SIGNAL(triggered()), mywidget, SLOT(pause()));
	connect(actionReset,SIGNAL(triggered()), mywidget, SLOT(reset()));
}
