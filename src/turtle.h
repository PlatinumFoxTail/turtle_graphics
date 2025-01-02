#ifndef TURTLE_H
#define TURTLE_H

#include "paintarea.h"

#include <QDebug>
#include <QObject>
#include <QString>
#include <QTimer>

class Turtle : public QObject
{
    //generated automatically when selecting QObject as Base Class in file setup
    Q_OBJECT

public:
    //Accepting a PaintArea and parent QObject reference.
    //Later generated automatically when selecting QObject as Base Class in file setup.
    explicit Turtle(PaintArea *paintArea, QObject *parent = nullptr);

    //moving turtle forward desired pixels
    void forward(double distance);

    //turning turtle desired angles
    void turn(double angleChange);

    //toggling drawing mode true/false
    void setDraw(bool draw);

    //reset turtle position
    void resetPosition();

    //getters for x, y, angle, and drawing
    double getX() const { return x; }
    double getY() const { return y; }
    double getAngle() const { return angle; }
    bool isDrawing() const { return drawing; }


private:
    PaintArea *paintArea;
    double x;
    double y;
    double angle;
    bool drawing;
};

#endif // TURTLE_H
