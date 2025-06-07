#include <estia-image.h>
#include <stdio.h>
#include <string.h>

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
     n=(width*channel_count*(y-1))+((x-1)*channel_count);
     printf ("print_pixel (%d, %d): %d, %d, %d", x, y, data[n], data[n+1], data[n+2]);
    }
    else {
        printf("ERROR");
    }
}

/*DEBUT FONCTIONS STATISTIQUES*/

void max_pixel (char *source_path){
    int width, height, channel_count, max, xmax, ymax, rmax, gmax, bmax, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    max = 0;
    xmax = 0;
    ymax = 0;
    rmax = 0;
    gmax = 0;
    bmax = 0;

    if (resultat){
        for (y = 0; y <= height; y++){
            for (x = 0; x <= width; x++){
                pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
                if (current_pixel != NULL) {
                    int current_rgb = current_pixel->R + current_pixel->G + current_pixel->B;
                    if (current_rgb > max) {
                        max = current_rgb;
                        xmax = x;
                        ymax = y;
                        rmax = current_pixel->R;
                        gmax = current_pixel->G;
                        bmax = current_pixel->B;
                    }
                }
            }            
        }
     printf ("max_pixel (%d, %d): %d, %d, %d",xmax ,ymax, rmax, gmax, bmax);
    }
    else {
        printf("erreur de lecture");
    }
}

void min_pixel (char *source_path){
    int width, height, channel_count, min, xmin, ymin, rmin, gmin, bmin, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    min = 255*3;
    xmin = 0;
    ymin = 0;
    rmin = 0;
    gmin = 0;
    bmin = 0;

    if (resultat){
        for (y = 0; y <= height; y++){
            for (x = 0; x <= width; x++){
                pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
                if (current_pixel != NULL) {
                    int current_rgb = current_pixel->R + current_pixel->G + current_pixel->B;
                    if (current_rgb < min) {
                        min = current_rgb;
                        xmin = x;
                        ymin = y;
                        rmin = current_pixel->R;
                        gmin = current_pixel->G;
                        bmin = current_pixel->B;
                    }
                }
            }            
        }
     printf ("min_pixel (%d, %d): %d, %d, %d",xmin ,ymin, rmin, gmin, bmin);
    }
    else {
        printf("erreur de lecture");
    }
}

void max_component (char *source_path, char t){
    int width, height, channel_count, max, xmax, ymax, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    max = 0;
    xmax = 0;
    ymax = 0;

    if (resultat){
        for (y = 0; y <= height; y++){
            for (x = 0; x <= width; x++){
                pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
                if (current_pixel != NULL) {
                    if (t == 'R'){
                        if (current_pixel->R > max){
                            max = current_pixel->R;
                            xmax = x;
                            ymax = y;
                        }
                    }
                    if (t == 'G'){
                        if (current_pixel->G > max){
                            max = current_pixel->G;
                            xmax = x;
                            ymax = y;
                        }
                    }
                    if (t == 'B'){
                        if (current_pixel->B > max){
                            max = current_pixel->B;
                            xmax = x;
                            ymax = y;
                        }
                    }
                }
            }            
        }
        if (t == 'R') {
            printf ("max_component R (%d, %d): %d", xmax, ymax, max);
        }
        if (t == 'G') {
            printf ("max_component G (%d, %d): %d", xmax, ymax, max);
        }
        if (t == 'B') {
            printf ("max_component B (%d, %d): %d", xmax, ymax, max);
        }
    }
    else {
        printf("erreur de lecture");
    }
}

void min_component (char *source_path, char t){
    int width, height, channel_count, min, xmin, ymin, i, j;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    min = 255;
    xmin = 0;
    ymin = 0;

    if (resultat){
        for (i = 1; i <= height; i++){
            for (j = 1; j <= width; j++){
                if (t == 'R'){
                    if (data[(width*channel_count)*(i-1)+(j-1)*channel_count] < min){
                        min = data[(width*channel_count)*(i-1)+(j-1)*channel_count];
                        xmin = j-1;
                        ymin = i-1;
                    }
                }
                if (t == 'G'){
                    if (data[(width*channel_count)*(i-1)+(j-1)*channel_count+1] < min){
                        min = data[(width*channel_count)*(i-1)+(j-1)*channel_count+1];
                        xmin = j-1;
                        ymin = i-1;
                    }
                }
                if (t == 'B'){
                    if (data[(width*channel_count)*(i-1)+(j-1)*channel_count+2] < min){
                        min = data[(width*channel_count)*(i-1)+(j-1)*channel_count+2];
                        xmin = j-1;
                        ymin = i-1;
                    }
                }
            }            
        }
        if (t == 'R') {
            printf ("min_component R (%d, %d): %d", xmin, ymin, min);
        }
        if (t == 'G') {
            printf ("min_component G (%d, %d): %d", xmin, ymin, min);
        }
        if (t == 'B') {
            printf ("min_component B (%d, %d): %d", xmin, ymin, min);
        }
    }
    else {
        printf("erreur de lecture");
    }
}

void stat_report (char *source_path){
    char nom_fichier_stat_report[256];
    
    /*créer fichier txt nommé par immage*/
    char *nom_image = strrchr(source_path, '/');
    if (nom_image != NULL) {
        nom_image++;
    }
    else {
        nom_image = source_path;
    }
    snprintf(nom_fichier_stat_report, sizeof(nom_fichier_stat_report), "stat_report_%s.txt", nom_image);
    freopen(nom_fichier_stat_report, "w", stdout);


    /*appel des différentes fonctions*/
    max_pixel (source_path);
    printf("\n\n");
    min_pixel (source_path);
    printf("\n\n");
    max_component (source_path, 'R');
    printf("\n\n");
    max_component (source_path, 'G');
    printf("\n\n");
    max_component (source_path, 'B');
    printf("\n\n");
    min_component (source_path, 'R');
    printf("\n\n");
    min_component (source_path, 'G');
    printf("\n\n");
    min_component (source_path, 'B');
    printf("\n\n");

}