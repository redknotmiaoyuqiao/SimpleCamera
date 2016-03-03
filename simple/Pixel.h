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

    uint32_t getR();
    uint32_t getG();
    uint32_t getB();

    void setPixel(uint32_t R,uint32_t G,uint32_t B);

    void setPixel(uint32_t color);
    uint32_t getColor();
};


#endif //SIMPLECAMERA_PIXEL_H
