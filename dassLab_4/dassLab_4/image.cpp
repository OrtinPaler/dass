#include "image.h"

Image::Image(QString path) {
    image = new QPixmap(path);
}

Image::~Image() {
    delete image;
}

QPixmap *Image::getImage() {
    return image;
}
