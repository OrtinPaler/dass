#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QRandomGenerator>
#include "rectangle.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *mainScene;
    QGraphicsView *view;
    Rectangle *item;
};

#endif // MAIN_WINDOW_H
