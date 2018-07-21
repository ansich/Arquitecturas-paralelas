/* 
 * File:   main.c
 * Author: AP3
 *
 * Created on 29 de enero de 2014, 12:55
 */

#include <stdio.h>
#include <stdlib.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Error: Usage %s image_file_name\n", argv[0]);
        return EXIT_FAILURE;
    }

    //CV_LOAD_IMAGE_COLOR = 1 forces the resultant IplImage to be colour.
    //CV_LOAD_IMAGE_GRAYSCALE = 0 forces a greyscale IplImage.
    //CV_LOAD_IMAGE_UNCHANGED = -1
    IplImage* Img = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);

    // Always check if the program can find the image file
    if (!Img) {
        printf("Error: file %s not found\n", argv[1]);
        return EXIT_FAILURE;
    }

    // a visualization window is created with title: image file name

    cvNamedWindow(argv[1], 1);

    // Img is shown in ’image’ window

    cvShowImage(argv[1], Img);
    cvWaitKey(3000);


    // Crea la imagen para la componete azul
    IplImage* ImgBaW = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);

    int fila, columna;

    for (fila = 0; fila < Img->height; fila++) {

        unsigned char *pImg = (unsigned char *) Img->imageData + fila * Img->
                widthStep;
        unsigned char *pImgBaW = (unsigned char *) ImgBaW->imageData + fila *
                ImgBaW->widthStep;


        for (columna = 0; columna < Img->width; columna++) {

            //Imagen BaW
            int blue = (*pImg * 0.114);
            pImg++;
            int green = (*pImg * 0.587);
            pImg++;
            int red = (*pImg * 0.299);
            pImg++;
            
            *pImgBaW++ = blue + green + red;
            *pImgBaW++ = blue + green + red;
            *pImgBaW++ = blue + green + red;
        }
    }


    // crea y muestras las ventanas con las imagenes
    cvNamedWindow("Componente BaW", CV_WINDOW_AUTOSIZE);
    cvShowImage("Componente BaW", ImgBaW);
    cvWaitKey(3000);

    // memory release for images before exiting the application
    cvReleaseImage(&Img);
    cvReleaseImage(&ImgBaW);
    // cvReleaseImage(&Img);
    // Self-explanatory
    cvDestroyWindow(argv[1]);
    cvDestroyWindow("Componente BaW");


    return EXIT_SUCCESS;
}