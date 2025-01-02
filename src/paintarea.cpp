#include "paintarea.h"
//paintarea::paintarea() {}
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <QTransform>


PaintArea::PaintArea(QWidget *parent)
    : QWidget(parent), line_width_(1)
{


    // Timer for animating
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PaintArea::updateLineLength);

    // Initialize media player
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/src/ouch.mp3"));

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}


void PaintArea::paintEvent(QPaintEvent *event) {
    //qDebug() << "PaintEvent called, drawing lines...";


    QPainter painter(this);

    QPixmap kuva(":/src/kuva_donatello.png");

    // Initialize end point for turtle image location
    QPoint end;

    // initialise currenline length for boundary checks
    int current_line_length = 0;


    // if no lines exist draw turlte in start position and return
    if (lines_.size() == 0){
        painter.drawPixmap(this->getWidth()/2-50,this->getHeight()/2-50,100,100,kuva);
        return;
    }

    // Draw completed lines
    for (int i = 0; i < currentLineIndex; i++) {
        auto [x, y, angle, len, width, col] = lines_[i];
        QPoint start(x, y);
        end = QPoint(x + len*std::cos(angle), y + len*std::sin(angle));
        pen_.setWidth(width);
        pen_.setColor(col);
        painter.setPen(pen_);
        painter.drawLine(start, end);
        current_line_length = len;
    }

    // Draw the currently animating line
    if (currentLineIndex < lines_.size()) {
        auto [x, y, angle, len, width, col] = lines_[currentLineIndex];
        QPoint start(x, y);
        end = QPoint(x + lineLength*std::cos(angle), y + lineLength*std::sin(angle));
        pen_.setWidth(width);
        pen_.setColor(col);
        painter.setPen(pen_);
        painter.drawLine(start, end);
        current_line_length = len;
    }

    // if turtle hits a wall play ouch sound
    if (end.x() <= 1 or end.y() <= 1 or end.y() >= this ->getHeight()-1 or end.x() >= this ->getWidth()-1){
        // Only play sound if turtle is moving and at the end of a line
        if (timer ->isActive() && lineLength >= current_line_length){
            player ->play();
        }

    }

    painter.drawPixmap(end.x()-50,end.y()-50,100,100,kuva);
}

void PaintArea::addLine(double startX, double startY, double angle, int len, bool drawing) {
    //qDebug() << "Adding line from" << startX << startY << "to" << endX << endY;
    int width = getLineWidth();
    QColor color = getLineColor();

    // if not drawing make line invisible
    if (!drawing){
         color.setAlpha(0);
    }
    TurtleLine tline(startX, startY, angle, len, width, color);
    lines_.append(tline);

    // start animating lines
    timer->start(15);
}

void PaintArea::updateLineLength() {
    if (lines_.size() == 0) {
        return;
    }
    // Increase current line length each time timer runs out
    lineLength += 1;
    if (currentLineIndex < lines_.size() && lineLength > lines_[currentLineIndex].length) {
        lineLength = 0;
        currentLineIndex = currentLineIndex +1;

    }

    // Call paint event if there are lines left
    if (currentLineIndex<=lines_.size()) {
        update();
    }

    // If all lines are drawn stop animating.
    if (currentLineIndex>=lines_.size()) {
        timer->stop();
    }
}

void PaintArea::clearArea() {
    lines_.clear();
    currentLineIndex = 0;
    lineLength = 0;
    update();
}

void PaintArea::setLineWidth(int width) {
    line_width_ = width;
}

void PaintArea::setLineColor(QColor color) {
    line_color_ = color;
}
