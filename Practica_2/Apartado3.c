/* 
 * File:   main.c
 * Author: AP3
 *
 * Created on 12 de febrero de 2014, 12:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Usage: %s image_file_name\n", argv[0]);
        return EXIT_FAILURE;
    }

    //CV_LOAD_IMAGE_COLOR = 1 forces the resultant IplImage to be colour.
    //CV_LOAD_IMAGE_GRAYSCALE = 0 forces a greyscale IplImage.
    //CV_LOAD_IMAGE_UNCHANGED = -1

    IplImage* Img1 = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
    IplImage* Img2 = cvLoadImage(argv[2], CV_LOAD_IMAGE_UNCHANGED);
    cvNamedWindow("Imagen transición", CV_WINDOW_AUTOSIZE);
    // Always check if the program can find a file
    if (!Img1) {
        printf("Error: fichero %s no leido\n", argv[1]);
        return EXIT_FAILURE;
    }
    if (!Img2) {
        printf("Error: fichero %s no leido\n", argv[2]);
        return EXIT_FAILURE;
    }
    IplImage* ImgTrans = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);

    int fila, columna;


    for (fila = 0; fila < Img1->height / 2; fila++) {

        unsigned char *pImg1 = (unsigned char *) Img2->imageData + ((Img1->height / 2) + fila) * Img2->
                widthStep;
        unsigned char *pImg2 = (unsigned char *) Img2->imageData + fila * Img2->
                widthStep;
        unsigned char *pImgTransInicio = (unsigned char *) ImgTrans->imageData + fila *
                ImgTrans->widthStep;
        unsigned char *pImgTransFin = (unsigned char *) ImgTrans->imageData + ((Img1->height / 2) + fila) *
                ImgTrans->widthStep;

        for (columna = 0; columna < Img1->width; columna++) {

            //Imagen Transición




            *pImgTransInicio++ = *pImg2++;
            *pImgTransInicio++ = *pImg2++;
            *pImgTransInicio++ = *pImg2++;

            *pImgTransFin++ = *pImg1++;
            *pImgTransFin++ = *pImg1++;
            *pImgTransFin++ = *pImg1++;

        }

        cvShowImage("Imagen transición", ImgTrans);
        cvWaitKey(70);

    }


    // a visualization window is created with title 'image'
    cvNamedWindow(argv[1], CV_WINDOW_AUTOSIZE);
    cvNamedWindow(argv[2], CV_WINDOW_AUTOSIZE);

    // img is shown in 'image' window
    cvShowImage(argv[1], Img1);
    cvShowImage(argv[2], Img2);

    cvWaitKey(0);
    return (EXIT_SUCCESS);
}