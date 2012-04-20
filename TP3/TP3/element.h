#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QString>
#include <QTextStream>

class Element : public QObject
{
    Q_OBJECT
public:
	Element(QObject *parent = 0, QString name = "");
	~Element();
	//void dumpObjectTree();

signals:

public slots:

};

extern QTextStream cout;

#endif // ELEMENT_H
