//
// Created by miaoyuqiao on 16/2/28.
//

#include "Pixel.h"

Pixel::Pixel(int * pixel)
{
    this->pixel = pixel;
}

int Pixel::getR()
{
    int pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>16);
    return pixel;
}

int Pixel::getG()
{
    int pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>8);
    return pixel;
}

int Pixel::getB()
{
    int pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>0);
    return pixel;
}

void Pixel::setPixel(int R,int G,int B)
{
    *this->pixel = 0xff000000 | ((R << 16) & 0x00ff0000) | ((G << 8) & 0x0000ff00) | (B & 0x000000ff);
}
