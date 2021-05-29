#ifndef ABSTRACT_IMAGE_H
#define ABSTRACT_IMAGE_H

#include <QGraphicsItem>

class AbstractImage {
protected:
    QPixmap *image;
public:
    virtual ~AbstractImage();
    virtual QPixmap *getImage() = 0;
};

#endif // ABSTRACT_IMAGE_H
