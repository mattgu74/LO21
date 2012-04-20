#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
	MyMainWindow(QWidget *parent = 0);

signals:

public slots:
	void about();

};

#endif // MYMAINWINDOW_H
