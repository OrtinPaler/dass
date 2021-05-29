#include "rectangle.h"

Rectangle::Rectangle(QObject *parent) : QObject(parent), QGraphicsItem() {
    QPixmap *_image = new QPixmap("/Users/ortin/Universe/6_semester/dass/dassLab_4/assets/ferrariLogo.jpg");
    rectSize = _image->size();
    ProxyImage *pimage = new ProxyImage("/Users/ortin/Universe/6_semester/dass/dassLab_4/assets/ferrariLogo.jpg");
    image = (AbstractImage *)pimage;
}

Rectangle::~Rectangle() {
    delete image;
}

QRectF Rectangle::boundingRect() const {
    return QRectF(x, y, rectSize.width(), rectSize.height());
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(Qt::black);
    painter->drawRect(x, y, rectSize.width(), rectSize.height());

    if (imageflag) {
        QPixmap *p = image->getImage();
        painter->drawPixmap(boundingRect().toRect(), *p);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void Rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::MouseButton::RightButton) {
        imageflag = true;
        this->update();
    }
    Q_UNUSED(event);
}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    // при отпускании мышью элемента, заменяем на обычный курсор стрелку
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
