//
// Created by miaoyuqiao on 16/3/1.
//

#include "Gray.h"

Gray::Gray(Mat * mat)
{
    this->mat = mat;
}
/*
 *
 * 普通灰度变换
 *
 */
void Gray::normalGray()
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            uint32_t gray = (R*19595 + G*38469 + B*7472) >> 16;

            pixel->setPixel(gray,gray,gray);
            delete (pixel);
        }
    }
}


/*
 *
 * 灰度反转变换 s = L - r,可以产生底片的效果
 *
 */
void Gray::negative()
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            uint32_t gray = (R*19595 + G*38469 + B*7472) >> 16;

            gray = 0xff - gray;

            pixel->setPixel(gray,gray,gray);
            delete (pixel);
        }
    }
}


/*
 *
 * 幂律(伽马)变换 s = c * r ` y
 * 可以用来调整对比度
 *
 */

void Gray::gamma(double c,double _y)
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            uint32_t gray = (R*19595 + G*38469 + B*7472) >> 16;

            gray = c * (pow(gray,_y));

            pixel->setPixel(gray,gray,gray);
            delete (pixel);
        }
    }
}


void Gray::logGray(double c)
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            uint32_t gray = (R*19595 + G*38469 + B*7472) >> 16;

            gray = c*log(gray);

            pixel->setPixel(gray,gray,gray);
            delete (pixel);
        }
    }
}
