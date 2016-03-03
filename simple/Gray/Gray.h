//
// Created by miaoyuqiao on 16/3/1.
//

#ifndef SIMPLECAMERA_GARY_H
#define SIMPLECAMERA_GARY_H

#include "../Mat.h"
#include "../Pixel.h"
#include <math.h>

class Gray {
private:
    Mat * mat;
public:
    Gray(Mat * mat);
    void normalGray();
    void negative();
    void gamma(double c,double _y);
    void logGray(double c);
};


#endif //SIMPLECAMERA_GARY_H
