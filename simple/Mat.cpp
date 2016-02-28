//
// Created by miaoyuqiao on 16/2/27.
//

#include "Mat.h"

Mat::Mat(int * array,int width,int height)
{
    this->width = width;
    this->height = height;
    this->array = array;
}

int* Mat::getArray()
{
    return this->array;
}

int Mat::getWidth()
{
    return this->width;
}

int Mat::getHeight()
{
    return this->height;
}

Pixel * Mat::getPixel(int x,int y)
{
    int * p_pix = &(this->array[this->width * y + x]);
    Pixel * pixel = new Pixel(p_pix);
    return pixel;
}