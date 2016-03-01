//
// Created by miaoyuqiao on 16/2/27.
//

#ifndef SIMPLECAMERA_MAT_H
#define SIMPLECAMERA_MAT_H

#include "Pixel.h"
#include <stdint.h>

class Mat {
private:
    uint32_t * array;
    int width;
    int height;
public:
    Mat(uint32_t * array,int width,int height);

    uint32_t * getArray();
    int getWidth();
    int getHeight();

    Pixel * getPixel(int x,int y);
};


#endif //SIMPLECAMERA_MAT_H
