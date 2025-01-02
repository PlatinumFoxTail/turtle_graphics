#include "turtle.h"
#include <QDebug>
#include <cmath> //for trigonometric functions
#include <algorithm> // for min functions

//constructor initializing PaintArea and QObject references.
//Later generated automatically when selecting QObject as Base Class in file setup
Turtle::Turtle(PaintArea *paintArea, QObject *parent)
    : QObject(parent)
    , paintArea(paintArea)
{
    x = paintArea->getWidth() / 2;
    y = paintArea->getHeight() / 2;
    angle = 0;
    drawing = true;
}

void Turtle::forward(double distance) {
    //x and y values prior forward change
    double initialX = x;
    double initialY = y;

    //converting degree to radians for tirgonometric functions
    double radians = angle * M_PI / 180.0;

    //calculating potential new x and y values
    double newX = x + distance * std::cos(radians);
    double newY = y + distance * std::sin(radians);

    double new_distance;

    //if new x and y values outside of PaintArea -> x and y set to boundry values
    if (newX < 0){
        newX = 0;
        new_distance = std::abs(std::abs(newX-initialX)/std::cos(radians));
        distance = std::min(new_distance, distance);

    }
    if (newX > paintArea->getWidth()){
        newX = paintArea->getWidth();
        new_distance = std::abs(std::abs(newX-initialX)/std::cos(radians));
        distance = std::min(new_distance, distance);
    }
    if (newY < 0){
        newY = 0;
        new_distance = std::abs(std::abs(newY-initialY)/std::sin(radians));
        distance = std::min(new_distance, distance);
    }
    if (newY > paintArea->getHeight()){
        newY = paintArea->getHeight();
        new_distance = std::abs(std::abs(newY-initialY)/std::sin(radians));
        distance = std::min(new_distance, distance);
    }

    distance = distance;
    newX = x + distance * std::cos(radians);
    newY = y + distance * std::sin(radians);

    //updating x and y values
    if (newX != x || newY != y) {
        x = newX;
        y = newY;
        paintArea->addLine(initialX, initialY, radians,distance, drawing);
    }
}


void Turtle::turn(double angleChange) {
    //updating angle based on angleChange
    angle += angleChange;
}

void Turtle::setDraw(bool draw) {

    //drawing = current turtle drawing state (true/false)
    //draw = next desired drawing state (true/false) from user
    if (drawing != draw) {
        drawing = draw;
    }
}

void Turtle::resetPosition() {
    x = paintArea->getWidth() / 2;
    y = paintArea->getHeight() / 2;
    angle = 0;
    drawing = true;
}

