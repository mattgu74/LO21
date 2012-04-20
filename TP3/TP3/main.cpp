#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication mainApp(argc, argv);

	QPushButton btnHello("Bonjour!", 0);
	btnHello.resize(200, 60);
	mainApp.setActiveWindow(&btnHello);
	btnHello.show();

	QObject::connect(&btnHello,SIGNAL(clicked()), &mainApp, SLOT(quit()));

	return mainApp.exec();
}
