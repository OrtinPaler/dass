#ifndef IMAGE_H
#define IMAGE_H

#include "abstract_image.h"

class Image : public AbstractImage {
public:
    Image(QString path);
    virtual ~Image();
    virtual QPixmap *getImage();
};

#endif // IMAGE_H
