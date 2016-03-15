//
// Created by miaoyuqiao on 16/3/10.
//

#include "Binary.h"

#include <android/log.h>
#define  LOG_TAG    "PhotoProcessing"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

Binary::Binary(YUVMat * yuvMat)
{
    this->yuvMat = yuvMat;
}
void Binary::BinaryByArea(int area_width,int area_height,float scale)
{
    int mat_width = this->yuvMat->getWidth();
    int mat_height = this->yuvMat->getHeight();

    for(int i=0;i<(mat_width/area_width) + 1;i++){
        for(int j=0;j<(mat_height/area_height) + 1;j++){

            uint32_t y_count = 0;

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
                    uint32_t color_y = this->yuvMat->getY(area_x,area_y);
                    y_count = y_count + color_y;
                }
            }

            uint8_t _threshold = y_count/(area_width * area_height);

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

                    uint8_t color_y = this->yuvMat->getY(area_x,area_y);

                    uint32_t color;

                    if(color_y<(_threshold * scale)){
                        color = 0xfe;
                    }else{
                        color = 0xef;
                    }

                    this->yuvMat->setY(color,area_x,area_y);
                }
            }
        }
    }
}