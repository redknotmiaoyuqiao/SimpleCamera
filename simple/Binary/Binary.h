//
// Created by miaoyuqiao on 16/3/1.
//

#ifndef SIMPLECAMERA_BINARY_H
#define SIMPLECAMERA_BINARY_H

#include "../Mat.h"
#include "../Pixel.h"
#include <stdint.h>

class Binary {
private:
    Mat * mat;
public:
    Binary(Mat * mat);

    void BinaryByThreshold(uint8_t threshold);
    void BinaryByArea(int area_width,int area_height,float scale);
};


#endif //SIMPLECAMERA_BINARY_H
