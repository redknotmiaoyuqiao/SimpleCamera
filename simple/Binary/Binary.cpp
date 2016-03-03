//
// Created by miaoyuqiao on 16/3/1.
//

#include "Binary.h"

Binary::Binary(Mat * mat)
{
    this->mat = mat;
}

void Binary::BinaryByThreshold(uint32_t threshold)
{
    for(int y=0;y<this->mat->getHeight();y++) {
        for (int x = 0; x < this->mat->getWidth(); x++) {
            Pixel *pixel = this->mat->getPixel(x, y);

            uint32_t R = pixel->getR();
            uint32_t G = pixel->getG();
            uint32_t B = pixel->getB();

            uint32_t gray = (R*19595 + G*38469 + B*7472) >> 16;

            uint8_t color;

            if(gray<threshold){
                color = 0x00;
            }else{
                color = 0xff;
            }

            pixel->setPixel(color,color,color);
            delete (pixel);
        }
    }
}


void Binary::BinaryByArea(int area_width,int area_height,float scale)
{

    int mat_width = this->mat->getWidth();
    int mat_height = this->mat->getHeight();

    for(int i=0;i<(mat_width/area_width) + 1;i++){
        for(int j=0;j<(mat_height/area_height) + 1;j++){

            uint32_t y_count = 0;

            uint32_t y_array[area_width * area_height];
            int yp = 0;

            int x_start = i * area_width;
            int x_end = (i+1) * area_width;
            int y_start = j * area_height;
            int y_end = (j+1) * area_height;

            if(x_end > mat_width){
                x_end = mat_width;
            }
            if(x_end<0){
                x_end = 0;
            }
            if(y_end>mat_height){
                y_end = mat_height;
            }
            if(y_end<0){
                y_end = 0;
            }

            for(int area_x=x_start;area_x<x_end; area_x++){
                for(int area_y=y_start;area_y<y_end;area_y++,yp++){
                    Pixel *pixel = this->mat->getPixel(area_x, area_y);

                    uint32_t R = pixel->getR();
                    uint32_t G = pixel->getG();
                    uint32_t B = pixel->getB();

                    uint32_t y = (R*19595 + G*38469 + B*7472) >> 16;

                    y_array[yp] = y;

                    y_count = y_count + y;

                    delete (pixel);
                }
            }

            uint8_t threshold = y_count/(area_width * area_height);
            yp = 0;


            x_start = i * area_width;
            x_end = (i+1) * area_width;
            y_start = j * area_height;
            y_end = (j+1) * area_height;

            if(x_end > mat_width){
                x_end = mat_width;
            }
            if(x_end<0){
                x_end = 0;
            }
            if(y_end>mat_height){
                y_end = mat_height;
            }
            if(y_end<0){
                y_end = 0;
            }

            for(int area_x=x_start;area_x<x_end; area_x++){
                for(int area_y=y_start;area_y<y_end;area_y++,yp++){
                    Pixel *pixel = this->mat->getPixel(area_x, area_y);

                    uint32_t y = y_array[yp];

                    uint32_t color;

                    if(y<(threshold * scale)){
                        color = 0x00;
                    }else{
                        color = 0xff;
                    }

                    pixel->setPixel(color,color,color);

                    delete (pixel);
                }
            }
        }
    }
}
