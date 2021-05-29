#ifndef WIDGET_H
#define WIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QWidget>

#include "abstract_interpreter.h"

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPlainTextEdit textArea;
    QHBoxLayout *layout;
    QVBoxLayout *mainLayout;
    QPushButton *interpret;
    QLabel *interpretLabel;

    AbstractInterpreter AInterpreter;

private slots:
    void interpretClicked();
};

#endif // WIDGET_H
