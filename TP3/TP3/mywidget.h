#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>

class MyWidget : public QWidget {
	Q_OBJECT

private:
	int r; // taille du disque
	int currX; // position du disque
	int currY;
	int speedX; // vitesse du disque
	int speedY;
	bool playing; // état de l'animation (jouer ou pause)
	QTimer * timer;

private slots:
	void newposition();

public slots:
	void play();
	void pause();
	void reset();

protected:
	void paintEvent(QPaintEvent * event);
public:
	MyWidget(QWidget * parent = 0, int size = 5,
			int limX = 460, int limY = 380,
			int sX = 1, int sY = 1);

};
#endif // MYWIDGET_H
