//
// Created by miaoyuqiao on 16/3/1.
//

#include "Blur.h"

Blur::Blur(Mat * mat)
{
    this->mat = mat;
}

void Blur::normalBlur()
{
    //x-1,y+1   x,y+1   x+1,y+1
    //x-1,y     x,y     x+1,y
    //x-1,y-1   x,y-1   x+1,y-1
    for(int y=0;y<this->mat->getHeight();y++) {
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel * pixel = this->mat->getPixel(x, y);

            Pixel * pixel1 = this->mat->getPixel(x-1, y+1);
            Pixel * pixel2 = this->mat->getPixel(x, y+1);
            Pixel * pixel3 = this->mat->getPixel(x+1, y+1);
            Pixel * pixel4 = this->mat->getPixel(x-1, y);
            Pixel * pixel5 = this->mat->getPixel(x+1, y);
            Pixel * pixel6 = this->mat->getPixel(x-1, y-1);
            Pixel * pixel7 = this->mat->getPixel(x, y-1);
            Pixel * pixel8 = this->mat->getPixel(x+1, y-1);

            uint32_t y = (pixel1->getR() +
                         pixel2->getR() +
                         pixel3->getR() +
                         pixel4->getR() +
                         pixel5->getR() +
                         pixel6->getR() +
                         pixel7->getR() +
                         pixel8->getR())/8;

            pixel->setPixel(y,y,y);
            delete (pixel);
        }
    }
}
void Blur::gaussianBlur()
{

}
