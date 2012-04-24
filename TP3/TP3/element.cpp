#include "element.h"
#include <QObjectList>
#include <QListIterator>

Element::Element(QObject *parent, QString name) :
	QObject(parent)
{
	setObjectName(name);
	cout << "-- Creer l'element " << name << "\n";
}
/*
void Element::dumpObjectTree()
{
	cout << "Element::" << objectName() << "\n";
	QListIterator<QObject*> it((QList<QObject*>) children());
	while(it.hasNext())
	{
		cout << "\t";
		it.next()->dumpObjectTree();
	}
}
*/
Element::~Element() {
	cout << "-- Liberer l'element " << objectName() << "\n";
}


QTextStream cout(stdout, QIODevice::WriteOnly);
