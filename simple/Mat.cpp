//
// Created by miaoyuqiao on 16/2/27.
//

#include "Mat.h"

Mat::Mat(uint32_t * array,int width,int height)
{
    this->width = width;
    this->height = height;
    this->array = array;
}

uint32_t* Mat::getArray()
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
    int i = this->width * y + x;
/*
    if(i >= (this->width * this->height)){
        return NULL;
    }

    if(i < 0){
        return NULL;
    }
    */

    uint32_t * p_pix = &(this->array[i]);
    Pixel * pixel = new Pixel(p_pix);
    return pixel;
}
