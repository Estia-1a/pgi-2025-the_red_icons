#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
     printf ("dimension: %d, %d \n", width,  height);
    }
    else {
        printf("ERROR");
    }
}

void first_pixel (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
     printf ("first_pixel: %d, %d, %d", data[0], data[1], data[2]);
    }
    else {
        printf("ERROR");
    }
}

void tenth_pixel (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
     printf ("tenth_pixel: %d, %d, %d", data[27], data[28], data[29]);
    }
    else {
        printf("ERROR");
    }

}

void second_line (char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
     printf ("second_line: %d, %d, %d", data[width*3], data[width*3+1], data[width*3+2]);
    }
    else {
        printf("erreur");
    }
}

void print_pixel( char *source_path, int x, int y ){
    int width, height, channel_count, n;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (resultat){
     n=(width*3*(y-1))+((x-1)*3);
     printf ("print_pixel %d, %d, %d,%d, %d", x, y, data[n], data[n+1], data[n+2]);
    }
    else {
        printf("ERROR");
    }
}

void max_pixel (char *source_path){
    int width, height, channel_count, max, xmax, ymax, rmax, gmax, bmax, i, j;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    max = 0;
    xmax = 0;
    ymax = 0;
    rmax = 0;
    gmax = 0;
    bmax = 0;

    if (resultat){
        for (i = 1; i <= height; i++){
            for (j = 1; j <= width; j++){
                if (data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count+1]+data[(width*channel_count)*(i-1)+(j-1)*channel_count + 2] > max){
                    max = data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count + 2];
                    xmax = j-1;
                    ymax = i-1;
                    rmax = data[(width*channel_count)*(i-1)+(j-1)*channel_count];
                    gmax = data[(width*channel_count)*(i-1)+(j-1)*channel_count+1];
                    bmax = data[(width*channel_count)*(i-1)+(j-1)*channel_count+2];
                }
            }            
        }
     printf ("max_pixel (%d, %d): %d, %d, %d",xmax ,ymax, rmax, gmax, bmax);
    }
    else {
        printf("ERROR");
    }
}

void min_pixel (char *source_path){
    int width, height, channel_count, min, xmin, ymin, rmin, gmin, bmin, i, j;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    min = 255*3;
    xmin = 0;
    ymin = 0;
    rmin = 0;
    gmin = 0;
    bmin = 0;

    if (resultat){
        for (i = 1; i <= height; i++){
            for (j = 1; j <= width; j++){
                if (data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count+1]+data[(width*channel_count)*(i-1)+(j-1)*channel_count + 2] < min) {
                    min = data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count]+data[(width*channel_count)*(i-1)+(j-1)*channel_count + 2];
                    xmin = j-1;
                    ymin = i-1;
                    rmin = data[(width*channel_count)*(i-1)+(j-1)*channel_count];
                    gmin = data[(width*channel_count)*(i-1)+(j-1)*channel_count+1];
                    bmin = data[(width*channel_count)*(i-1)+(j-1)*channel_count+2];
                }
            }            
        }
     printf ("max_pixel (%d, %d): %d, %d, %d",xmin ,ymin, rmin, gmin, bmin);
    }
    else {
        printf("ERROR");
    }
}