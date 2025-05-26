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
                    xmax = i;
                    ymax = j;
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