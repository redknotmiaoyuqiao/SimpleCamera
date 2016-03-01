//
// Created by miaoyuqiao on 16/2/28.
//

#ifndef SIMPLECAMERA_PIXEL_H
#define SIMPLECAMERA_PIXEL_H

#include <stdint.h>

class Pixel {
private:
    uint32_t * pixel;
public:

    Pixel(uint32_t * pixel);

    uint8_t getR();
    uint8_t getG();
    uint8_t getB();

    void setPixel(uint8_t R,uint8_t G,uint8_t B);

    void setPixel(uint32_t color);
    uint32_t getColor();
};


#endif //SIMPLECAMERA_PIXEL_H
