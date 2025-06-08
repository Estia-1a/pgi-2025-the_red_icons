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
        printf("ERROR");
    }
}

void mirror_vertical (char *source_path){

    int width, height, channel_count, i, j, k, current_rgb ;
    unsigned char *data;
    unsigned char *mirror_vertical;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_vertical, &width, &height, &channel_count);
    
    for (i=0; i<height; i++){
        for (j=1; j<width+1; j++){
            for (k=0; k<3; k++){
                current_rgb = 3*width*i+k;
                mirror_vertical[3*(width-j)+current_rgb] = data[3*(j-1)+current_rgb];
            }
        }
    }

    if (resultat){
        write_image_data("C:/WORKSPACE/image.png", mirror_vertical, width, height);
    }
    else {
        printf("NULL");
    }
}