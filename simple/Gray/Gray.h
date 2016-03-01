//
// Created by miaoyuqiao on 16/3/1.
//

#ifndef SIMPLECAMERA_GARY_H
#define SIMPLECAMERA_GARY_H

#include "../Mat.h"
#include "../Pixel.h"

class Gray {
private:
    Mat * mat;
public:
    Gray(Mat * mat);
    void normalGray();
};


#endif //SIMPLECAMERA_GARY_H
