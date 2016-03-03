//
// Created by miaoyuqiao on 16/3/3.
//

#ifndef SIMPLECAMERA_COLOR_H
#define SIMPLECAMERA_COLOR_H

#include "../Mat.h"
#include "../Pixel.h"
#include <math.h>

class Color {
private:
    Mat * mat;
public:
    Color(Mat * mat);
    void gamma(double c,double _y);
    void negative();
};


#endif //SIMPLECAMERA_COLOR_H
