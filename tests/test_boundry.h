#ifndef TEST_BOUNDARY_H
#define TEST_BOUNDARY_H

#include <QObject>
#include <QtTest/QtTest>
#include <QApplication>
#include "../src/paintarea.h"
#include "../src/turtle.h"

class TestBoundary : public QObject {
    Q_OBJECT

private slots:
    void testBoundaryConditions() {
        //initializing QApplication instance
        int argc = 0;
        char **argv = nullptr;
        QApplication app(argc, argv);

        //creating PaintArea and Turtle instances
        PaintArea paintArea(nullptr);
        paintArea.resize(400, 400);
        Turtle turtle(&paintArea);

        //check that right window boundry holds
        turtle.forward(1000);
        QCOMPARE(turtle.getX(), static_cast<double>(paintArea.getWidth()));

        //check that bottom window boundry holds
        turtle.turn(90);
        turtle.forward(1000);
        QCOMPARE(turtle.getY(), static_cast<double>(paintArea.getHeight()));

        //check that left window boundry holds
        turtle.turn(90);
        turtle.forward(1000);
        QCOMPARE(turtle.getX(), 0.0);

        //check that top window boundry holds
        turtle.turn(90);
        turtle.forward(1000);
        QCOMPARE(turtle.getY(), 0.0);

        //check that turtle is at top left corner after last move
        QCOMPARE(turtle.getX(), 0.0);
        QCOMPARE(turtle.getY(), 0.0);
    }
};

#endif // TEST_BOUNDARY_H
