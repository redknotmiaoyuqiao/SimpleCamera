//
// Created by miaoyuqiao on 16/2/28.
//

#include "Pixel.h"

Pixel::Pixel(uint32_t * pixel)
{
    this->pixel = pixel;
}

uint32_t Pixel::getR()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>16);
    return (uint8_t)pixel;
}

uint32_t Pixel::getG()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>8);
    return (uint8_t)pixel;
}

uint32_t Pixel::getB()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>0);
    return (uint8_t)pixel;
}

uint32_t Pixel::getColor()
{
    return *this->pixel;
}

void Pixel::setPixel(uint32_t R,uint32_t G,uint32_t B)
{
    if(R>0xff){
        R = 0xff;
    }
    if(G>0xff){
        G = 0xff;
    }
    if(B>0xff){
        B = 0xff;
    }

    *this->pixel = 0xff000000 | ((R << 16) & 0x00ff0000) | ((G << 8) & 0x0000ff00) | (B & 0x000000ff);
}

void Pixel::setPixel(uint32_t color)
{
    *this->pixel = color;
}
