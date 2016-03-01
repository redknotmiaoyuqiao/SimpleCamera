//
// Created by miaoyuqiao on 16/3/1.
//

#ifndef SIMPLECAMERA_BLUR_H
#define SIMPLECAMERA_BLUR_H

#include "../Mat.h"
#include "../Pixel.h"

class Blur {
private:
    Mat * mat;
public:
    Blur(Mat * mat);

    void normalBlur();
    void gaussianBlur();
};


#endif //SIMPLECAMERA_BLUR_H
