#include "proxy_image.h"

ProxyImage::ProxyImage(QString path) {
    this->path = path;
}

QPixmap *ProxyImage::getImage() {
    if (!realImage)
        realImage = new Image(path);

    return realImage->getImage();
}

ProxyImage::~ProxyImage() {
    delete realImage;
}
