//
// Created by miaoyuqiao on 16/3/10.
//

#ifndef FACTORYEYE_YUVMAT_H
#define FACTORYEYE_YUVMAT_H

#include <stdint.h>

class YUVMat {
private:
    uint32_t * y_array;
    uint32_t * u_array;
    uint32_t * v_array;

    int width;
    int height;
public:
    YUVMat(uint32_t * y_array,int width,int height);

    uint32_t getY(int x,int y);
    void setY(uint32_t color_y,int x,int y);

    int getWidth();
    int getHeight();
};


#endif //FACTORYEYE_YUVMAT_H
