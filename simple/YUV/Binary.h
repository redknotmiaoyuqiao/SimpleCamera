//
// Created by miaoyuqiao on 16/3/10.
//

#ifndef FACTORYEYE_BINARY_H
#define FACTORYEYE_BINARY_H

#include "../YUVMat.h"

class Binary {
private:
    YUVMat * yuvMat;
public:
    Binary(YUVMat * yuvMat);
    void BinaryByArea(int area_width,int area_height,float scale);
};


#endif //FACTORYEYE_BINARY_H
