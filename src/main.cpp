#include <QApplication>
#include <QDebug>                //for debugging output
#include <QGuiApplication>       //generated automatically in Qt Quick Application setup
#include <QQmlApplicationEngine> //generated automatically in Qt Quick Application setup
#include "turtle_window.h"

int main(int argc, char *argv[])
{ //generated automatically in Qt Quick Application setup
    QApplication app(argc, argv);

    //generated automatically in Qt Quick Application setup
    QQmlApplicationEngine engine;
    turtle_window window;
    window.move(100,0);

    window.show();
    return app.exec();
}
