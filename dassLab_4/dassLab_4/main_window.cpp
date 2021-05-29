#include "main_window.h"

static int randomBetween(int low, int high) {
    return QRandomGenerator::global()->generate() % ((high + 1) - low) + low;
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // устанавливаем размеры окна приложения
    this->resize(640,640);
    this->setFixedSize(640,640);

    mainScene = new QGraphicsScene(this);
    mainScene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view = new QGraphicsView();
    // устанавливаем размер graphicsView
    view->resize(600,600);
    // устанавливаем графическую сцену в graphicsView
    view->setScene(mainScene);
    // настраиваем рендер
    view->setRenderHint(QPainter::Antialiasing);
    // кэш фона
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    // устанавливаем размер сцены
    mainScene->setSceneRect(0,0,500,500);

    // создаем графический элемент
    item = new Rectangle(view);
    item->setPos(randomBetween(30, 470), randomBetween(30,470));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    mainScene->addItem(item);

    view->show();
}

MainWindow::~MainWindow() {
  delete view;
  delete mainScene;
  delete item;
}
