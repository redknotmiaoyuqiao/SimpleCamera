//
// Created by miaoyuqiao on 16/2/28.
//

#include "Pixel.h"

Pixel::Pixel(uint32_t * pixel)
{
    this->pixel = pixel;
}

uint8_t Pixel::getR()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>16);
    return (uint8_t)pixel;
}

uint8_t Pixel::getG()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>8);
    return (uint8_t)pixel;
}

uint8_t Pixel::getB()
{
    uint32_t pixel = *this->pixel;
    pixel = 0xff0000ff & (pixel>>0);
    return (uint8_t)pixel;
}

uint32_t Pixel::getColor()
{
    return *this->pixel;
}

void Pixel::setPixel(uint8_t R,uint8_t G,uint8_t B)
{
    uint32_t R32 = R;
    uint32_t G32 = G;
    uint32_t B32 = B;
    *this->pixel = 0xff000000 | ((R32 << 16) & 0x00ff0000) | ((G32 << 8) & 0x0000ff00) | (B32 & 0x000000ff);
}

void Pixel::setPixel(uint32_t color)
{
    *this->pixel = color;
}
