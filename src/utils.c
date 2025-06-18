#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channel_count, const unsigned int x, const unsigned int y ){
  if (x >= width || y >= height) {
    return NULL;
  }
  if (data == 0) {
    return NULL;
  }
  unsigned long décalage = y * width * channel_count + x * channel_count;
  return (pixelRGB*) &data[décalage];

}

int set_Pixel( unsigned char* data, const unsigned int width, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel){
unsigned long décalage = y * width * n + x * n;
data[décalage] = pixel->R;
data[décalage+1] = pixel->G;
data[décalage+2] = pixel->B;

return 0;
}

unsigned char min(unsigned char R, unsigned char G, unsigned char B) {
    unsigned char result = R ;
    if (G < result) {
        result = G ;
    }
    if (B < result) {
        result = B ;
    }
    return result;
}

unsigned char max(unsigned char R, unsigned char G, unsigned char B) {
    unsigned char result = R ;
    if (G > result) {
        result = G ;
    }
    if (B > result) {
        result = B ;
    }
    return result;
}