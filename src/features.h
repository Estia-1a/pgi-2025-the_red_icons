#ifndef FEATURES_H
#define FEATURES_H

/*Tutoriel*/
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
void color_gray_luminance (char *source_path);
void color_desaturate (char *source_path);

/*Transform*/
void mirror_horizontal (char *source_path);
void mirror_vertical (char *source_path);
void mirror_total (char *source_path);
void rotate_cw (char *source_path);
void rotate_acw (char *source_path);

/*Resize*/
void scale_nearest (char *source_path, float t);
void scale_bilinear (char *source_path, float t);

#endif
