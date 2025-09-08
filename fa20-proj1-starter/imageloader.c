/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error: Failed to open file");
        return NULL;
    }

    char format[3];
    fscanf(fp, "%2s", format);
    if (format[0] != 'P' || format[1] != '3') {
        fprintf(stderr, "Error: Invalid PPM format. Expected P3.\n");
        fclose(fp);
        return NULL;
    }

    Image *img = (Image *) malloc(sizeof(Image));
    if (img == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for Image struct.\n");
        fclose(fp);
        return NULL;
    }

    if (fscanf(fp, "%u %u", &(img->cols), &(img->rows)) != 2) {
        fprintf(stderr, "Error: Failed to read image dimensions.\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    int max_val;
    if (fscanf(fp, "%d", &max_val) != 1) {
        fprintf(stderr, "Error: Failed to read max color value.\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    img->image = (Color **) malloc(img->rows * sizeof(Color *));
    if (img->image == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for row pointers.\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    for (uint32_t i = 0; i < img->rows; i++) {
        img->image[i] = (Color *) malloc(img->cols * sizeof(Color));
        if (img->image[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for row %u.\n", i);
            for (uint32_t j = 0; j < i; j++) {
                free(img->image[j]);
            }
            free(img->image); // 释放行指针数组
            free(img);      // 释放Image结构体
            fclose(fp);
            return NULL;
        }
    }

    for (uint32_t i = 0; i < img->rows; i++) {
        for (uint32_t j = 0; j < img->cols; j++) {
            int r, g, b;
            if (fscanf(fp, "%d %d %d", &r, &g, &b) != 3) {
                fprintf(stderr, "Error: Failed to read pixel data at (%u, %u).\n", i, j);
                freeImage(img);
                fclose(fp);
                return NULL;
            }
            img->image[i][j].R = (uint8_t)r;
            img->image[i][j].G = (uint8_t)g;
            img->image[i][j].B = (uint8_t)b;
        }
    }

    fclose(fp);
    return img;
}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
    if (image == NULL || image->image == NULL) {
        fprintf(stderr, "Error: Cannot write a NULL or invalid image.\n");
        return;
    }

    fprintf(stdout, "P3\n");
    fprintf(stdout, "%u %u\n", image->cols, image->rows);
    fprintf(stdout, "255\n");

    for (uint32_t i = 0; i < image->rows; i++) {
        for (uint32_t j = 0; j < image->cols; j++) {
            Color pixel = image->image[i][j];
            fprintf(stdout, "%3d %3d %3d", pixel.R, pixel.G, pixel.B);
            if (j < image->cols - 1) {
                fprintf(stdout, "   ");
             }else {
                fprintf(stdout, "\n"); 
            }
        }
    }
}

//Frees an image
void freeImage(Image *image) 
{
    if (image == NULL) {
        return; 
    }

    for (uint32_t i = 0; i < image->rows; i++) {
        // image->image[i] 是一个指向 Color 数组的指针
        free(image->image[i]);
    }

    free(image->image);

    free(image);
}
