//
// Created by miaoyuqiao on 16/3/1.
//

#include "Gray.h"

Gray::Gray(Mat * mat)
{
    this->mat = mat;
}

void Gray::normalGray()
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint8_t R = pixel->getR();
            uint8_t G = pixel->getG();
            uint8_t B = pixel->getB();

            uint8_t y = (R*19595 + G*38469 + B*7472) >> 16;

            pixel->setPixel(y,y,y);
            delete (pixel);
        }
    }
}