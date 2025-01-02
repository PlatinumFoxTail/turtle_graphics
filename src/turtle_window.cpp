#include "turtle_window.h"
#include "paintarea.h"
#include "turtle.h"
#include "ui_turtle_window.h"

#include <QColorDialog>
#include <QRegularExpression>
#include <QWidget>

#include <QFileDialog> //for opening file dialog
#include <QMessageBox> //for showing warnings and errors
#include <QString>     //for QString operations
#include <QStringList> //for handling list of strings
#include <QTextEdit>   //for interacting with QTextEdit

#include "nlohmann/json.hpp" //for JSON parsing. Downloaded from https://github.com/nlohmann/json/releases
#include <fstream>           //for reading JSON file

turtle_window::turtle_window(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::turtle_window)
{
    ui_->setupUi(this);

    paintArea_ = ui_->turtle_widget;

    turtle_ = new Turtle(paintArea_, this);
    //connect(turtle_, &Turtle::drawLine, paintArea_, &PaintArea::addLine);

    //connects the Start button to the handler (i.e. handles the specific click event)
    connect(ui_->commandLinkButton,
            &QPushButton::clicked,
            this,
            &turtle_window::handleStartButtonClick);

    //connect the reset button to the handler
    connect(ui_->commandLinkButton_3,
            &QPushButton::clicked,
            this,
            &turtle_window::handleResetButtonClick);

    //connects the Load button to the handler (i.e. handles the specific click event)
    connect(ui_->commandLinkButton_2,
            &QPushButton::clicked,
            this,
            &turtle_window::handleLoadButtonClick);

    //setup draw button
    connect(ui_->pen_button, &QRadioButton::toggled, turtle_, &Turtle::setDraw);

    //setup width slider
    width_slider_ = ui_->width_slider;
    width_slider_->setRange(0, 16);
    connect(width_slider_, &QSlider::valueChanged, paintArea_, &PaintArea::setLineWidth);

    //setup color picker
    color_frame_ = ui_->color_frame;
    color_frame_->setStyleSheet(QString("background-color: black;"));
    connect(ui_->color_picker_button,
            &QPushButton::clicked,
            this,
            &turtle_window::handleColorButtonClick);
}

turtle_window::~turtle_window() {
    delete turtle_;
    delete ui_;
}


//handles actions associtated with "Start" button
void turtle_window::handleStartButtonClick() {
    //qDebug() << "Start button clicked";

    if (!turtle_) {
        qDebug() << "Turtle instance not found";
        return;
    }

    //fetching command string from the command line user interface
    QString commands = ui_->textEdit->toPlainText();

    //parsing command string into separate commands based on whitespace and add to list
    static const QRegularExpression whitespaceRegex("\\s+");
    QStringList commandList = commands.split(whitespaceRegex, Qt::SkipEmptyParts);

    //Passing valid commands to turtle class
    for (const QString &command : commandList) {

        if (command.startsWith("setDraw")) {
            //if parsed content of setDraw command = true, then draw = true
            auto draw = extractInsideParentheses(command);

            if (draw.toLower() == "true") {turtle_ ->setDraw(true);}

            else if (draw.toLower() == "false") {turtle_ ->setDraw(false);}

            else{qDebug() << "Command unknown:" << command;}


        } else if (command.startsWith("forward(")) {
            //parsing value from forward command
            auto distance = extractInsideParentheses(command);

            if (isConvertibleToDouble(distance)) {turtle_ -> forward(distance.toDouble());}

            else {qDebug() << "Command unknown:" << command;}


        } else if (command.startsWith("turn(")) {
            //parsing value from turn command
            auto angleChange = extractInsideParentheses(command);

            if (isConvertibleToDouble(angleChange)) {turtle_ -> turn(angleChange.toDouble());}

            else {qDebug() << "Command unknown:" << command;}

        } else {
            qDebug() << "Command unknown:" << command;
        }
    }
}

// return whats inside the paranteses
QString turtle_window::extractInsideParentheses(const QString &command) {
    return command.mid(command.indexOf('(') + 1,command.indexOf(')') - command.indexOf('(') - 1);
}

// check if string can be converted to double
bool turtle_window::isConvertibleToDouble(const QString &str) {
    bool ok;
    str.toDouble(&ok);
    return ok;
}

//handles actions associated with "Load" button
void turtle_window::handleLoadButtonClick() {
    //opening file dialog for opening JSON file
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open JSON File",
                                                    "",
                                                    "JSON Files (*.json)");
    if (fileName.isEmpty()) {
        return; //user canceled file dialog
    }

    //try block to handle the JSON file
    try {
        //opening and parssing JSON file
        std::ifstream file(fileName.toStdString());

        //using nlohmann's release v3.11.3 for handling JSON files in C++
        nlohmann::json jsonData;
        file >> jsonData;

        //converting JSON commands to forward(x), turn(y), and setDraw(z) commands.
        //x is pcs of pxs, and y is angles in degrees, and z is true or false.
        QString commandText;
        for (const auto &cmd : jsonData) {
            if (cmd.contains("command") && cmd.contains("value")) {
                std::string command = cmd["command"];

                if (command == "setDraw") {
                    bool value = cmd["value"];
                    commandText += QString::fromStdString(command) + "("
                                   + (value ? "true" : "false") + ") ";
                } else if (command == "forward" || command == "turn") {
                    int value = cmd["value"];
                    commandText += QString::fromStdString(command) + "(" + QString::number(value)
                                   + ") ";
                } else {
                    QMessageBox::warning(this,
                                         "Warning",
                                         "Command not known: " + QString::fromStdString(command));
                }
            } else {
                QMessageBox::warning(this,
                                     "Warning",
                                     "JSON command not proper: "
                                         + QString::fromStdString(cmd.dump()));
            }
        }

        //passing formatted commandText from JSON file into the command line interface (=textEdit object)
        ui_->textEdit->setPlainText(commandText);
    }
    //catch block if try block of JSON file did not succeed
    catch (const std::exception &e) {
        QMessageBox::critical(this,
                              "Error",
                              "Failed to load JSON file: " + QString::fromStdString(e.what()));
    }
}

void turtle_window::handleResetButtonClick() {
    paintArea_->clearArea();
    turtle_->resetPosition();
}

void turtle_window::handleColorButtonClick() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {
        paintArea_->setLineColor(color);
        color_frame_->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    }
}
