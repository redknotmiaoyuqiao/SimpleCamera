//
// Created by miaoyuqiao on 16/2/27.
//

#ifndef SIMPLECAMERA_MAT_H
#define SIMPLECAMERA_MAT_H

#include "Pixel.h"

class Mat {
private:
    int * array;
    int width;
    int height;
public:
    Mat(int * array,int width,int height);

    int * getArray();
    int getWidth();
    int getHeight();

    Pixel * getPixel(int x,int y);
};


#endif //SIMPLECAMERA_MAT_H
