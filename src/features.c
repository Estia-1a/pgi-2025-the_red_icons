#include <estia-image.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
    int width, height, channel_count;
    unsigned char *data;
    
    // lire donées immage//
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    pixelRGB *current_pixel = get_pixel(data, width, height, channel_count, x, y);

    // afficher le resultat si valide //
    if (resultat !=0) {
        
        unsigned char R = current_pixel->R;
        unsigned char G = current_pixel->G;
        unsigned char B = current_pixel->B;
        printf ("print_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
    }
    else {
        printf("erreur lecture immage");
    }    
    //liberer mémoire//
    free(data);
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
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
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
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
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
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
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
    int width, height, channel_count, min, xmin, ymin, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    min = 255;
    xmin = 0;
    ymin = 0;

    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
                if (current_pixel != NULL) {
                    if (t == 'R'){
                        if (current_pixel->R < min){
                            min = current_pixel->R;
                            xmin = x;
                            ymin = y;
                        }
                    }
                    if (t == 'G'){
                        if (current_pixel->G < min){
                            min = current_pixel->G;
                            xmin = x;
                            ymin = y;
                        }
                    }
                    if (t == 'B'){
                        if (current_pixel->B < min){
                            min = current_pixel->B;
                            xmin = x;
                            ymin = y;
                        }
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
    
    /*créer fichier txt nommé par immage*/
    char nom_fichier_stat_report[256];
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

/*DEBUT FONCTIONS COLORS*/

void color_red (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                data[pixel_offset +1] = 0;
                data[pixel_offset +2] = 0;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_green (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                data[pixel_offset ] = 0;
                data[pixel_offset +2] = 0;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_blue (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                data[pixel_offset ] = 0;
                data[pixel_offset +1] = 0;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_gray (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                unsigned long pixel_moyenne = (data[pixel_offset] + data[pixel_offset + 1] + data[pixel_offset + 2])/3;
                data[pixel_offset ] = pixel_moyenne ;
                data[pixel_offset + 1 ] = pixel_moyenne ;
                data[pixel_offset + 2 ] = pixel_moyenne ;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_invert (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                data[pixel_offset ] = 255 - data[pixel_offset] ;
                data[pixel_offset + 1 ] = 255 - data[pixel_offset + 1 ] ;
                data[pixel_offset + 2 ] = 255 - data[pixel_offset + 2 ] ;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_gray_luminance (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                float pixel_moyenne = 0.21f * data[pixel_offset] + 0.72f * data[pixel_offset + 1 ] + 0.07f * data[pixel_offset + 2 ] ;
                data[pixel_offset ] = pixel_moyenne ;
                data[pixel_offset + 1 ] = pixel_moyenne ;
                data[pixel_offset + 2 ] = pixel_moyenne ;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

void color_desaturate (char *source_path){
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                unsigned long pixel_offset = y * width * channel_count + x * channel_count;
                unsigned char R = data[pixel_offset];
                unsigned char G = data[pixel_offset + 1 ];
                unsigned char B = data[pixel_offset + 2 ]; 
                unsigned long pixel_moyenne = (min(R, G, B) + max(R, G, B)) / 2 ;
                data[pixel_offset ] = pixel_moyenne ;
                data[pixel_offset + 1 ] = pixel_moyenne ;
                data[pixel_offset + 2 ] = pixel_moyenne ;
            }
        }
    int write_success = write_image_data("image_out.bmp", data, width, height);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data);
    }
    else {
        printf("erreur de lecture");
    }
}

/*Fonctions transform*/

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
        write_image_data("image_out.bmp", mirror_vertical, width, height);
    }
    else {
        printf("NULL");
    }
}

void mirror_horizontal (char *source_path){

    int width, height, channel_count, i, j, k, current_rgb ;
    unsigned char *data;
    unsigned char *mirror_horizontal;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_horizontal, &width, &height, &channel_count);
    
    for (i=0; i<height; i++){
    	for (j=1; j<width+1; j++){
            for (k=0; k<3; k++){
                current_rgb = 3*width*i+k;
                mirror_horizontal[3*(width-j)+current_rgb] = data[3*(j-1)+current_rgb];
            }
        }
    }
    if (resultat){
        write_image_data("images/image_out.bmp", mirror_horizontal, width, height);
    }
    else {
        printf("NULL");
    }
}
void mirror_vertical (char *source_path){

    int width, height, channel_count, i, j, current_rgb;
    unsigned char *data;
    unsigned char *mirror_vertical;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_vertical, &width, &height, &channel_count);
    
    for (i=0; i<height; i++){
        for (j=0; j<width*3; j++){
                current_rgb = 3*width*i;
                mirror_vertical[j+(height-1)*width*3-current_rgb]= data[j+current_rgb];
        }
    }

    if (resultat){
        write_image_data("images/image_out.bmp", mirror_vertical, width, height);
    }
    else {
        printf("NULL");
    }
}

void mirror_total (char *source_path){

    int width, height, channel_count, i, j, k, current_rgb;
    unsigned char *data;
    unsigned char *mirror_vertical;
    unsigned char *mirror_total;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_vertical, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_total, &width, &height, &channel_count);
    
    for (i=0; i<height; i++){
        for (j=1; j<width+1; j++){
            for (k=0; k<3; k++){
                current_rgb = 3*width*i+k;
                mirror_vertical[3*(width-j)+current_rgb] = data[3*(j-1)+current_rgb];
            }
        }
    }

    for (i=0; i<height; i++){
        for (j=0; j<width*3; j++){
                current_rgb = 3*width*i;
                mirror_total[j+(height-1)*width*3-current_rgb]= mirror_vertical[j+current_rgb];
        }
    }

    if (resultat){
        write_image_data("image_out.bmp", mirror_total, width, height);
    }
    else {
        printf("NULL");
    }
}

    
void rotate_cw (char *source_path){

    int width, height, channel_count, x, y;
    unsigned char *data;
    unsigned char *rotate_cw;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &rotate_cw, &width, &height, &channel_count);

    for (y=0; y < height; y++){
        for (x=0 ; x < width; x++){
            int x_cible = height - y - 1;
            int y_cible = x ;
            pixelRGB* original_pixel = get_pixel(data, width, height, channel_count, x , y);
            pixelRGB* transform_pixel = get_pixel(rotate_cw, width, height, channel_count, x_cible , y_cible);
            transform_pixel->R = original_pixel->R;
            transform_pixel->G = original_pixel->G;
            transform_pixel->B = original_pixel->B;
        }
    }
    if (resultat){
        write_image_data("image_out.bmp", rotate_cw, height, width);
    }
    else {
        printf("NULL");
    }
}

/*Début fonctions resize*/
void rotate_acw (char *source_path){

    int width, height, channel_count, x, y;
    unsigned char *data;
    unsigned char *rotate_acw;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &rotate_acw, &width, &height, &channel_count);
    
    for (y=0; y < height; y++){
        for (x=0 ; x < width; x++){
            int x_cible = y;
            int y_cible = width-x-1;
            pixelRGB* original_pixel = get_pixel(data, width, height, channel_count, x , y);
            pixelRGB* transform_pixel = get_pixel(rotate_acw, width, height, channel_count, x_cible , y_cible);
            transform_pixel->R = original_pixel->R;
            transform_pixel->G = original_pixel->G;
            transform_pixel->B = original_pixel->B;
        }
    }
    if (resultat){
        write_image_data("image_out.bmp", rotate_acw, height, width);
    }
    else {
        printf("NULL");
    }
}

void scale_crop(char *sourcePath, int x, int y, int width_crop, int height_crop) {
    int width, height, channel_count;
    unsigned char *data;
    unsigned char *crop_image;

    read_image_data(sourcePath, &data, &width, &height, &channel_count);

    int crop_x = x - width_crop / 2;
    int crop_y = y - height_crop / 2;

    if (crop_x < 0) {
        width_crop += crop_y;
        crop_x = 0;
    }
    if (crop_x + width_crop > width) {
        width_crop = width - crop_x;
    }

    if (crop_y < 0) {
        height_crop += crop_y;
        crop_y = 0;
    }
    if (crop_y + height_crop > height) {
        height_crop = height - crop_y;
    }

    crop_image = (unsigned char *)malloc(width_crop * height_crop * channel_count * sizeof(unsigned char));

    for (int destY = 0; destY < height_crop; destY++) {
        for (int destX = 0; destX < width_crop; destX++) {
            int sourceX = crop_x + destX;
            int sourceY = crop_y + destY;

            pixelRGB* sourcePixel = get_pixel(data, width, height, channel_count, sourceX, sourceY);
            
            int destPixelOffset = (destY * width_crop + destX) * channel_count;

            if (sourcePixel != NULL) {
                crop_image[destPixelOffset] = sourcePixel->R;
                crop_image[destPixelOffset + 1] = sourcePixel->G;
                crop_image[destPixelOffset + 2] = sourcePixel->B;
            } else {
                crop_image[destPixelOffset] = 0;
                crop_image[destPixelOffset + 1] = 0;
                crop_image[destPixelOffset + 2] = 0;
            }
        }
    }
    write_image_data("image_out.bmp", crop_image, width_crop, height_crop);
}

void scale_nearest(char *source_path, float t) {
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    /*création du tableau résultat à écrire*/
    unsigned char *data_result;
    double height_result = ceilf(height * t) ;
    double width_result = ceilf(width * t) ;
    double dimension_result = height_result * width_result * channel_count ;
    data_result = (unsigned char *)malloc(dimension_result) ;
    
    if (resultat) {
        for (y = 0; y < height_result; y++) {
            for (x = 0; x < width_result; x++) {
                unsigned long pixel_offset = y * width_result * channel_count + x * channel_count ;
                float x_origin = (float)x / t ;
                float y_origin = (float)y / t ;
                int x_nearest = (int)roundf(x_origin) ;
                int y_nearest = (int)roundf(y_origin) ;
                if (x_nearest < 0) x_nearest = 0 ;
                if (y_nearest < 0) y_nearest = 0 ;
                if (x_nearest >= width) x_nearest = width - 1 ;
                if (y_nearest >= height) y_nearest = height - 1 ;
                unsigned pixel_origin = y_nearest * width * channel_count + x_nearest * channel_count ;
                data_result[pixel_offset] = data[pixel_origin] ;
                data_result[pixel_offset + 1 ] = data[pixel_origin + 1 ] ;
                data_result[pixel_offset + 2 ] = data[pixel_origin + 2 ] ;
            }
        }
    int write_success = write_image_data("image_out.bmp", data_result, width_result, height_result);
    if (write_success){
        printf("print ok");
    }
    else {
        printf("print fail");
    }
    free_image_data(data) ;
    free(data_result);
    }
    else {
        printf("erreur de lecture");
    }
}

void scale_bilinear(char *source_path, float t) {
    int width, height, channel_count, x, y;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    /*création du tableau résultat à écrire*/
    unsigned char *data_result;
    double height_result = ceilf(height * t) ;
    double width_result = ceilf(width * t) ;
    double dimension_result = height_result * width_result * channel_count ;
    data_result = (unsigned char *)malloc(dimension_result) ;
    
    if (resultat) {
        for (y = 0; y < height_result; y++) {
            for (x = 0; x < width_result; x++) {
                unsigned long pixel_offset = y * width_result * channel_count + x * channel_count ;
                float x_origin = (float)x / t ;
                float y_origin = (float)y / t ;
                /*calcul des positions des pixels originaux les plus proches*/
                int x_hg = (int)floorf(x_origin);
                int y_hg = (int)floorf(y_origin);
                if (x_hg < 0 ) x_hg = 0 ;
                if (y_hg < 0 ) y_hg = 0 ;
                if (x_hg >= width) x_hg = width - 1 ;
                if (y_hg >= height) y_hg = height - 1 ;
                pixelRGB* pixel_hg = get_pixel(data, width, height, channel_count, x_hg, y_hg);
                int x_hd = x_hg + 1 ;
                int y_hd = y_hg ;
                if (x_hd < 0 ) x_hd = 0 ;
                if (y_hd < 0 ) y_hd = 0 ;
                if (x_hd >= width) x_hd = width - 1 ;
                if (y_hd >= height) y_hd = height - 1 ;
                pixelRGB* pixel_hd = get_pixel(data, width, height, channel_count, x_hd, y_hd);
                int x_bg = x_hg ;
                int y_bg = y_hg + 1 ;
                if (x_bg < 0 ) x_bg = 0 ;
                if (y_bg < 0 ) y_bg = 0 ;
                if (x_bg >= width) x_bg = width - 1 ;
                if (y_bg >= height) y_bg = height - 1 ;
                pixelRGB* pixel_bg = get_pixel(data, width, height, channel_count, x_bg, y_bg);
                int x_bd = x_hg + 1 ;
                int y_bd = y_hg + 1 ;
                if (x_bd < 0 ) x_bd = 0 ;
                if (y_bd < 0 ) y_bd = 0 ;
                if (x_bd >= width) x_bd = width - 1 ;
                if (y_bd >= height) y_bd = height - 1 ;
                pixelRGB* pixel_bd = get_pixel(data, width, height, channel_count, x_bd, y_bd);

                /*calcul des valeurs de R*/
                float dx = x_origin - x_hg ;
                float dy = y_origin - y_hg ;
                data_result[pixel_offset] = (1 - dx) * (1 - dy) * pixel_hg->R + (1- dx) * (dy) * pixel_bg->R + (dx) * (1 - dy) * pixel_hd->R + (dx) * (dy) * pixel_bd->R;
                data_result[pixel_offset + 1] = (1 - dx) * (1 - dy) * pixel_hg->G + (1- dx) * (dy) * pixel_bg->G + (dx) * (1 - dy) * pixel_hd->G + (dx) * (dy) * pixel_bd->G;
                data_result[pixel_offset + 2] = (1 - dx) * (1 - dy) * pixel_hg->B + (1- dx) * (dy) * pixel_bg->B + (dx) * (1 - dy) * pixel_hd->B + (dx) * (dy) * pixel_bd->B;                
            }
        }
    int write_success = write_image_data("image_out.bmp", data_result, width_result, height_result);
    if (write_success){
        printf("write ok");
    }
    else {
        printf("write fail");
    }
    free_image_data(data) ;
    free(data_result);
    }
    else {
        printf("erreur de lecture");
    }
}
