/********************************************************************************
** Form generated from reading UI file 'turtle_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURTLE_WINDOW_H
#define UI_TURTLE_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <paintarea.h>

QT_BEGIN_NAMESPACE

class Ui_turtle_window
{
public:
    PaintArea *turtle_widget;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QTextEdit *textEdit;
    QRadioButton *pen_button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *slider_layout;
    QLabel *width_slider_label;
    QSlider *width_slider;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *color_picker_button;
    QFrame *color_frame;
    QLabel *label;
    QTextBrowser *textBrowser;
    QCommandLinkButton *commandLinkButton_3;

    void setupUi(QWidget *turtle_window)
    {
        if (turtle_window->objectName().isEmpty())
            turtle_window->setObjectName("turtle_window");
        turtle_window->resize(1000, 800);
        turtle_widget = new PaintArea(turtle_window);
        turtle_widget->setObjectName("turtle_widget");
        turtle_widget->setGeometry(QRect(0, 0, 731, 571));
        commandLinkButton = new QCommandLinkButton(turtle_window);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(790, 640, 151, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(14);
        font.setBold(true);
        commandLinkButton->setFont(font);
        commandLinkButton->setAutoFillBackground(true);
        commandLinkButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 85, 0);"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        commandLinkButton->setIcon(icon);
        commandLinkButton->setAutoRepeatDelay(300);
        commandLinkButton_2 = new QCommandLinkButton(turtle_window);
        commandLinkButton_2->setObjectName("commandLinkButton_2");
        commandLinkButton_2->setGeometry(QRect(790, 740, 151, 41));
        commandLinkButton_2->setFont(font);
        commandLinkButton_2->setAutoFillBackground(true);
        commandLinkButton_2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 85, 127);"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        commandLinkButton_2->setIcon(icon1);
        textEdit = new QTextEdit(turtle_window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(90, 640, 621, 141));
        textEdit->setInputMethodHints(Qt::InputMethodHint::ImhMultiLine);
        pen_button = new QRadioButton(turtle_window);
        pen_button->setObjectName("pen_button");
        pen_button->setGeometry(QRect(510, 590, 201, 31));
        pen_button->setFont(font);
        pen_button->setCheckable(true);
        pen_button->setChecked(true);
        pen_button->setAutoRepeat(false);
        pen_button->setAutoExclusive(true);
        verticalLayoutWidget = new QWidget(turtle_window);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(760, 490, 212, 54));
        slider_layout = new QVBoxLayout(verticalLayoutWidget);
        slider_layout->setObjectName("slider_layout");
        slider_layout->setContentsMargins(0, 0, 0, 0);
        width_slider_label = new QLabel(verticalLayoutWidget);
        width_slider_label->setObjectName("width_slider_label");
        width_slider_label->setFont(font);
        width_slider_label->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        width_slider_label->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        width_slider_label->setFrameShape(QFrame::Shape::Panel);
        width_slider_label->setFrameShadow(QFrame::Shadow::Plain);
        width_slider_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        slider_layout->addWidget(width_slider_label);

        width_slider = new QSlider(verticalLayoutWidget);
        width_slider->setObjectName("width_slider");
        width_slider->setValue(0);
        width_slider->setSliderPosition(0);
        width_slider->setOrientation(Qt::Orientation::Horizontal);

        slider_layout->addWidget(width_slider);

        verticalLayoutWidget_2 = new QWidget(turtle_window);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(760, 560, 218, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        color_picker_button = new QPushButton(verticalLayoutWidget_2);
        color_picker_button->setObjectName("color_picker_button");
        color_picker_button->setFont(font);

        verticalLayout->addWidget(color_picker_button);

        color_frame = new QFrame(verticalLayoutWidget_2);
        color_frame->setObjectName("color_frame");
        color_frame->setFrameShape(QFrame::Shape::StyledPanel);
        color_frame->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(color_frame);

        label = new QLabel(turtle_window);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 590, 411, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("System")});
        font1.setPointSize(17);
        font1.setBold(true);
        label->setFont(font1);
        textBrowser = new QTextBrowser(turtle_window);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(740, 50, 251, 401));
        textBrowser->setFont(font);
        textBrowser->setTabletTracking(true);
        commandLinkButton_3 = new QCommandLinkButton(turtle_window);
        commandLinkButton_3->setObjectName("commandLinkButton_3");
        commandLinkButton_3->setGeometry(QRect(790, 690, 151, 41));
        commandLinkButton_3->setFont(font);
        commandLinkButton_3->setAutoFillBackground(true);
        commandLinkButton_3->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 85, 0);"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop));
        commandLinkButton_3->setIcon(icon2);
        commandLinkButton_3->setAutoRepeatDelay(300);

        retranslateUi(turtle_window);

        QMetaObject::connectSlotsByName(turtle_window);
    } // setupUi

    void retranslateUi(QWidget *turtle_window)
    {
        turtle_window->setWindowTitle(QCoreApplication::translate("turtle_window", "turtle_window", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("turtle_window", "START", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("turtle_window", "LOAD", nullptr));
        textEdit->setHtml(QCoreApplication::translate("turtle_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        pen_button->setText(QCoreApplication::translate("turtle_window", "Toggle Drawing", nullptr));
        width_slider_label->setText(QCoreApplication::translate("turtle_window", "Width Slider (slide)", nullptr));
#if QT_CONFIG(accessibility)
        width_slider->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        color_picker_button->setText(QCoreApplication::translate("turtle_window", " Color Picker (click)", nullptr));
        label->setText(QCoreApplication::translate("turtle_window", "INSERT COMMANDS BELOW, THEN CLICK START:", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("turtle_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'System'; font-size:14pt; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; text-decoration: underline;\">Commands : </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><s"
                        "pan style=\" font-family:'Sustem'; font-size:12pt; font-weight:400;\">- </span><span style=\" font-size:12pt;\">forward(</span><span style=\" font-size:12pt; font-style:italic;\">x  </span><span style=\" font-size:12pt;\">)</span><span style=\" font-size:12pt; font-weight:400;\"> : </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400;\">Moves turtle forward by </span><span style=\" font-size:12pt; font-weight:400; font-style:italic;\">x</span><span style=\" font-size:12pt; font-weight:400;\"> amount in the preset direction.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- <span style=\" font-size:12pt;\""
                        ">turn(</span><span style=\" font-size:12pt; font-style:italic;\">x  </span><span style=\" font-size:12pt;\">)</span><span style=\" font-size:12pt; font-weight:400;\"> : </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400;\">Turns the turtle by </span>x<span style=\" font-size:12pt; font-weight:400;\"> amount of degrees to the right.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400;\">- </span><span style=\" font-size:12pt;\">setDraw(</span><span style=\" font-size:12pt; font-style:italic;\">true / false </span><span style=\" font-size:12pt;\">)</span><span st"
                        "yle=\" font-size:12pt; font-weight:400;\"> : </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400;\">Makes the turtle draw while moving(=</span><span style=\" font-size:12pt; font-weight:400; font-style:italic;\">true </span><span style=\" font-size:12pt; font-weight:400;\">) or not(=</span><span style=\" font-size:12pt; font-weight:400; font-style:italic;\">false </span><span style=\" font-size:12pt; font-weight:400;\">).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:400;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("turtle_window", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class turtle_window: public Ui_turtle_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURTLE_WINDOW_H
