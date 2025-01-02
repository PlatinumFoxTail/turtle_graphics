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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_turtle_window
{
public:
    QFrame *turtle_frame;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QTableView *tableView;

    void setupUi(QWidget *turtle_window)
    {
        if (turtle_window->objectName().isEmpty())
            turtle_window->setObjectName("turtle_window");
        turtle_window->resize(800, 600);
        turtle_frame = new QFrame(turtle_window);
        turtle_frame->setObjectName("turtle_frame");
        turtle_frame->setGeometry(QRect(0, 0, 621, 471));
        turtle_frame->setFrameShape(QFrame::Shape::StyledPanel);
        turtle_frame->setFrameShadow(QFrame::Shadow::Raised);
        commandLinkButton = new QCommandLinkButton(turtle_window);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(620, 480, 172, 41));
        commandLinkButton_2 = new QCommandLinkButton(turtle_window);
        commandLinkButton_2->setObjectName("commandLinkButton_2");
        commandLinkButton_2->setGeometry(QRect(620, 530, 172, 41));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        commandLinkButton_2->setIcon(icon);
        textEdit = new QTextEdit(turtle_window);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 480, 621, 64));
        progressBar = new QProgressBar(turtle_window);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(650, 430, 118, 23));
        progressBar->setValue(24);
        tableView = new QTableView(turtle_window);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(630, 10, 161, 351));

        retranslateUi(turtle_window);

        QMetaObject::connectSlotsByName(turtle_window);
    } // setupUi

    void retranslateUi(QWidget *turtle_window)
    {
        turtle_window->setWindowTitle(QCoreApplication::translate("turtle_window", "turtle_window", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("turtle_window", "START", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("turtle_window", "STOP / RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class turtle_window: public Ui_turtle_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURTLE_WINDOW_H
