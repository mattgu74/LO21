#include "mywidget.h"
#include <QtGui>
#include "element.h"

MyWidget::MyWidget(QWidget * parent, int size, int limX, int limY, int sX, int sY) :
    QWidget(parent)
{
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()), this, SLOT(newposition()));
	resize(limX, limY);
	speedX = sX;
	speedY = sY;
	r = size;
	reset();
}

void MyWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::red);
	painter.drawEllipse(QPoint(currX,currY), r, r);
}

void MyWidget::newposition()
{
	int dt = timer->interval();
	currX += speedX * dt;
	currY += speedY * dt;
	if(currX < 0) { currX = -currX; speedX = -speedX; }
	if(currY < 0) { currY = -currY; speedY = -speedY; }
	if(currX > width()) { currX = 2*width() - currX; speedX = -speedX; }
	if(currY > height()) { currY = 2*height() - currY; speedY = -speedY; }
	update();
}

void MyWidget::play()
{
	timer->start(100);
}

void MyWidget::pause()
{
	timer->stop();
}

void MyWidget::reset()
{
	currX = (int)((float)qrand() * (float)width() / (float)RAND_MAX);
	currY = (int)((float)qrand() * (float)height() / (float)RAND_MAX);
}

