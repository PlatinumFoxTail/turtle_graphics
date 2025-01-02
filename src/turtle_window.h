#ifndef TURTLE_WINDOW_H
#define TURTLE_WINDOW_H

#include <QFrame>
#include <QSlider>
#include <QWidget>
#include <QMainWindow>
#include "turtle.h"


QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;

namespace Ui {
class turtle_window;
}
QT_END_NAMESPACE
class PaintArea;

//! [0]
class turtle_window : public QMainWindow
{
    Q_OBJECT

public:
    turtle_window(QWidget *parent = nullptr);
    ~turtle_window();
    Turtle *getTurtle() const { return turtle_; }


    // private slots:
    //     void shapeChanged();
    //     void penChanged();
    //     void brushChanged();

private slots:
    void handleStartButtonClick();
    void handleResetButtonClick();
    void handleLoadButtonClick();
    void handleColorButtonClick();

private:
    // returns number associated with command
    QString extractInsideParentheses(const QString &command);
    bool isConvertibleToDouble(const QString &str);

    Ui::turtle_window *ui_;
    PaintArea *paintArea_;
    QSlider *width_slider_;
    QFrame *color_frame_;
    Turtle *turtle_;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *otherOptionsLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;
};
//! [0]
#endif // TURTLE_WINDOW_H
