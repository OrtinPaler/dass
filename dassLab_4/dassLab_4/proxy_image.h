#ifndef PROXY_IMAGE_H
#define PROXY_IMAGE_H

#include "image.h"

class ProxyImage : public AbstractImage {
private:
    Image *realImage = NULL;
    QString path;

public:
    ProxyImage(QString path);

    virtual ~ProxyImage();
    virtual QPixmap *getImage();
};

#endif // PROXY_IMAGE_H
