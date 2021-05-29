#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), layout(new QHBoxLayout), mainLayout(new QVBoxLayout(this)), interpret(new QPushButton("Interpret")) {
    // устанавливаем размеры окна приложения
    this->resize(640,640);
    this->setFixedSize(640,640);
    textArea.setBaseSize(500, 500);

    layout->addWidget(interpret);

    mainLayout->addWidget(&textArea);
    mainLayout->addLayout(layout);

    connect(interpret, &QPushButton::clicked, this, &Widget::interpretClicked);
}

Widget::~Widget() {}

void Widget::interpretClicked() {
    // получаем текст с области и запускаем интерпертации
    QString context = textArea.toPlainText();
    AInterpreter.interpret(&context);
    textArea.setPlainText(context);
}
