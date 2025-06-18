# Daily Evaluation 18/06 - 15:53:19
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 19/23 :  82%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                           | Stdout       |
| :---------- | :---------- | :--------------------------------------------------------------------------------------------------------------------- | :----------- |
| dimension   | 4/4 :  100% |                                                                                                                        |              |
| first_pixel | 5/5 :  100% |                                                                                                                        |              |
| tenth_pixel | 5/5 :  100% |                                                                                                                        |              |
| second_line | 5/5 :  100% |                                                                                                                        |              |
| print_pixel | 0/4 :  0%   | Print Pixel (0,0) : 0,0,0<br>Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0 | <br><br><br> |

# Milestone  statistiques
Score : 25/26 :  96%
## Detail by Feature
| Feature         | Score       | Missed tests        | Stdout                    |
| :-------------- | :---------- | :------------------ | :------------------------ |
| max_pixel       | 4/4 :  100% |                     |                           |
| min_pixel       | 3/4 :  75%  | Min Pixel white 8x8 | min_pixel (0, 0): 0, 0, 0 |
| min_component R | 3/3 :  100% |                     |                           |
| min_component G | 3/3 :  100% |                     |                           |
| min_component B | 3/3 :  100% |                     |                           |
| max_component R | 3/3 :  100% |                     |                           |
| max_component G | 3/3 :  100% |                     |                           |
| max_component B | 3/3 :  100% |                     |                           |

# Milestone  colors
Score : 35/35 :  100%
## Detail by Feature
| Feature              | Score       | Missed tests | Stdout |
| :------------------- | :---------- | :----------- | :----- |
| color_red            | 5/5 :  100% |              |        |
| color_blue           | 5/5 :  100% |              |        |
| color_green          | 5/5 :  100% |              |        |
| color_gray           | 5/5 :  100% |              |        |
| color_invert         | 5/5 :  100% |              |        |
| color_gray_luminance | 5/5 :  100% |              |        |
| color_desaturate     | 5/5 :  100% |              |        |

# Milestone  transform
Score : 7.68/15 :  51%
## Detail by Feature
| Feature           | Score         | Missed tests                             | Stdout |
| :---------------- | :------------ | :--------------------------------------- | :----- |
| rotate_cw         | 1/3 :  33%    | rotate large image<br>rotate high image  | <br>   |
| rotate_acw        | 1/3 :  33%    | rotate large image<br>rotate high image  | <br>   |
| mirror_horizontal | 1.34/3 :  44% | mirror square image<br>mirror high image | <br>   |
| mirror_vertical   | 1.34/3 :  44% | mirror square image<br>mirror high image | <br>   |
| mirror_total      | 3/3 :  100%   |                                          |        |

# Milestone  resize
Score : 6/60 :  10%
## Detail by Feature
| Feature        | Score       | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :---------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 6/20 :  30% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 1.3                                                                                                                                                                                                     | print ok<br>print ok<br>print ok… |
| scale_bilinear | 0/20 :  0%  | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | write ok<br>write ok<br>write ok… |
| scale_crop     | 0/20 :  0%  | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

