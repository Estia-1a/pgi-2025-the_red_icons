#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension (char *source_path);
void first_pixel (char *source_path);
void tenth_pixel (char *source_path);
void second_line (char *source_path);
void print_pixel( char *source_path, int x, int y );
/*Statistiques*/
void max_pixel (char *source_path);
void min_pixel (char *source_path);
void max_component (char *source_path, char t);
void min_component (char *source_path, char t);
void stat_report (char *source_path);
/*Colors*/
void color_red (char *source_path);
void color_green (char *source_path);
void color_blue (char *source_path);
void color_gray (char *source_path);
void color_invert (char *source_path);

#endif
