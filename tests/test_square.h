#ifndef TEST_SQUARE_H
#define TEST_SQUARE_H

#include <QObject>
#include <QtTest/QtTest>
#include <QApplication>
#include <cmath>
#include "../src/paintarea.h"

class TestSquare : public QObject {
    Q_OBJECT

private slots:
    void testSquareDrawing() {
        //initializing QApplication instance
        int argc = 0;
        char **argv = nullptr;
        QApplication app(argc, argv);

        //creating PaintArea instance
        PaintArea paintArea(nullptr);
        paintArea.resize(400, 400);

        //setting up initial position of turtle, angle of turtle, and length of square sides
        double startX = paintArea.getWidth() / 2 - 50; //midpoint of window
        double startY = paintArea.getHeight() / 2 - 50;//midpoint of window
        double angle = 0;       //(rad)
        double sideLength = 50; //(px)

        //qDebug() << "Initial Position: (" << startX << ", " << startY << ")";

        //adding lines to form square
        double currentX = startX;
        double currentY = startY;
        for (int i = 0; i < 4; ++i) {
            paintArea.addLine(currentX, currentY, angle, sideLength, true); //drawing side and saving it
            //updating position
            currentX += sideLength * std::cos(angle);
            currentY += sideLength * std::sin(angle);
            //qDebug() << "Line " << i + 1 << " Position: (" << currentX << ", " << currentY << ")";
            angle -= M_PI_2; //turning 90 degrees to left
        }

        //checking 4 lines added
        QCOMPARE(paintArea.lines().size(), 4);

        //checking all lines are of correct length
        for (const TurtleLine& line : paintArea.lines()) {
            QCOMPARE(line.length, sideLength);
        }

        //fetching last line drawn
        const TurtleLine& lastLine = paintArea.lines().last();

        //checking end coordinates of the last line equal the starting coordinates
        QCOMPARE(lastLine.x + lastLine.length * std::cos(lastLine.angle), startX);
        QCOMPARE(lastLine.y + lastLine.length * std::sin(lastLine.angle), startY);
    }
};

#endif // TEST_SQUARE_H
