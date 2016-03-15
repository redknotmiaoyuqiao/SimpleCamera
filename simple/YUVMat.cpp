//
// Created by miaoyuqiao on 16/3/10.
//

#include "YUVMat.h"

YUVMat::YUVMat(uint32_t * y_array,int width,int height)
{
    this->y_array = y_array;
    this->height = height;
    this->width = width;
}

uint32_t YUVMat::getY(int x,int y)
{
    int i = this->width * y + x;
    uint32_t p_pix = this->y_array[i];
    return p_pix;
}

void YUVMat::setY(uint32_t color_y,int x,int y)
{
    int i = this->width * y + x;
    this->y_array[i] = color_y;
}

int YUVMat::getWidth()
{
    return this->width;
}
int YUVMat::getHeight()
{
    return this->height;
}