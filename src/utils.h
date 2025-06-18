#ifndef UTILS_H
#define UTILS_H
#include <stddef.h>

typedef struct _pixelRGB {
  unsigned char R;
  unsigned char G;
  unsigned char B;
} pixelRGB ;

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channel_count, const unsigned int x, const unsigned int y );
int set_Pixel( unsigned char* data, const unsigned int width, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);

#endif
