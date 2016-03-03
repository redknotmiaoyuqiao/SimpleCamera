//
// Created by miaoyuqiao on 16/3/3.
//

#include "Color.h"


Color::Color(Mat * mat)
{
    this->mat = mat;
}

void Color::gamma(double c,double _y)
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            R = c * (pow(R,_y));
            G = c * (pow(G,_y));
            B = c * (pow(B,_y));

            pixel->setPixel(R,G,B);
            delete (pixel);
        }
    }
}

void Color::negative()
{
    for(int y=0;y<this->mat->getHeight();y++){
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x,y);
            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            R = 0xff - R;
            G = 0xff - G;
            B = 0xff - B;

            pixel->setPixel(R,G,B);
            delete (pixel);
        }
    }
}