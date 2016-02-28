//
// Created by miaoyuqiao on 16/2/28.
//

#ifndef SIMPLECAMERA_PIXEL_H
#define SIMPLECAMERA_PIXEL_H


class Pixel {
private:
    int * pixel;
public:

    Pixel(int * pixel);

    int getR();
    int getG();
    int getB();

    void setPixel(int R,int G,int B);
};


#endif //SIMPLECAMERA_PIXEL_H
