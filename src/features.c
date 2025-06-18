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
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
                unsigned char pixel_min = 255 ;
                unsigned char pixel_max = 0 ;
                unsigned long pixel_moyenne = (pixel_min + pixel_max) / 2 ;
                data[pixel_offset ] = pixel_moyenne ;
                data[pixel_offset + 1 ] = pixel_moyenne ;
                data[pixel_offset + 2 ] = pixel_moyenne ;
            }
        }
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
                float pixel_moyenne = 0.21f * data[pixel_offset] + 0.72f * data[pixel_offset + 1 ] + 0.07f * data[pixel_offset + 2 ] ;
                data[pixel_offset ] = pixel_moyenne ;
                data[pixel_offset + 1 ] = pixel_moyenne ;
                data[pixel_offset + 2 ] = pixel_moyenne ;
            }
        }
    int write_success = write_image_data("images/image_out.bmp", data, width, height);
    if (write_success){
        printf("sauvegarde des données du tableau réussie");
    }
    else {
        printf("erreur de sauvegarde des données");
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
        write_image_data("images/image_out.bmp", mirror_vertical, width, height);
    }
    else {
        printf("NULL");
    }
}

void mirror_horizontal (char *source_path){

    int width, height, channel_count, i, j, current_rgb;
    unsigned char *data;
    unsigned char *mirror_horizontal;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &mirror_horizontal, &width, &height, &channel_count);
    
    for (i=0; i<height; i++){
        for (j=0; j<width*3; j++){
                current_rgb = 3*width*i;
                mirror_horizontal[j+(height-1)*width*3-current_rgb]= data[j+current_rgb];
        }
    }

    if (resultat){
        write_image_data("images/image_out.bmp", mirror_horizontal, width, height);
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
        write_image_data("images/image_out.bmp", mirror_total, width, height);
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

void scale_crop (char *source_path, int x, int y, int width_crop, int height_crop){
    int width, height, channel_count, x_origine, y_origine, x_crop, y_crop;
    unsigned char *data;
    unsigned char *crop_image;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &crop_image, &width, &height, &channel_count);

    x_crop=0;
    y_crop=0;

    for (y_origine = y-height_crop/2 ; y_origine > height_crop+y_origine; y_origine++){
        for (x_origine = x-width_crop/2 ; x_origine > width_crop+x_origine; x_origine++){
            pixelRGB* original_pixel = get_pixel(data, width, height, channel_count, x_origine , y_origine);
            pixelRGB* crop_pixel = get_pixel(crop_image, width, height, channel_count, x_crop , y_crop);
            crop_pixel->R = original_pixel->R;
            crop_pixel->G = original_pixel->G;
            crop_pixel->B = original_pixel->B;
            x_crop+=1;
        }
        y_crop+=1;
        x_crop=0;
    }

    if (resultat){
        write_image_data("image_out.bmp", crop_image, width_crop, height_crop);
    }
    else {
        printf("NULL");
    }

}

test push