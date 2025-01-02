#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QBrush>
#include <QLine>
#include <QList>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>

struct TurtleLine
{
    double x;
    double y;
    double angle;
    int length;
    int width;
    QColor color;

    TurtleLine(double x, double y, double angle, int len, int w, const QColor &c = Qt::black)
        : x(x)
        , y(y)
        , angle(angle)
        , length(len)
        , width(w)
        , color(c)
    {}
};

class PaintArea : public QWidget
{
    Q_OBJECT

public:
    PaintArea();
    explicit PaintArea(QWidget *parent = nullptr);


    //exposing PaintArea dimensions for boundry checks
    int getWidth() const { return this->width(); }
    int getHeight() const { return this->height(); }

    int getLineWidth() { return line_width_; }
    QColor getLineColor() { return line_color_; }

    //getter method to access lines for testing
    const QList<TurtleLine>& lines() const { return lines_; }

public slots:
    void addLine(double startX, double startY, double angle, int len, bool drawing);
    void updateLineLength();
    void clearArea();
    void setLineWidth(int width);
    void setLineColor(QColor color);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPen pen_;
    int line_width_;
    QColor line_color_;
    QBrush brush_;
    QPixmap pixmap_;
    QList<TurtleLine> lines_;
    // Which line are we animating now
    int currentLineIndex = 0;
    // What is the current length of that line
    int lineLength = 0;
    QTimer *timer;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // PAINTAREA_H
