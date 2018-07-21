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



    // Crea la imagen para la componete verde

    IplImage* ImgGREEN = cvCreateImage(cvSize(Img->width, Img->height * 4), IPL_DEPTH_8U, 3);

    int fila1, columna1;

    for (fila1 = 0; fila1 < Img->height; fila1++) {

        unsigned char *pImg1 = (unsigned char *) Img->imageData + fila1 * Img->
                widthStep;
        unsigned char *pImgGREEN = (unsigned char *) ImgGREEN->imageData + fila1 *
                ImgGREEN->widthStep;

        for (columna1 = 0; columna1 < Img->width; columna1++) {

            //Imagen RED
            *pImgGREEN++ = 0;
            pImg1++;
            *pImgGREEN++ = *pImg1++;
            *pImgGREEN++ = 0;
            pImg1++;
        }
        


    }

    // fin ejercicio 2

    // crea y muestras las ventanas con las imagenes

    cvNamedWindow("Componente GREEN", 0);
    cvShowImage("Componente GREEN", ImgGREEN);
    cvWaitKey(0);



    // memory release for images before exiting the application
    cvReleaseImage(&Img);

    cvReleaseImage(&ImgGREEN);
    // Self-explanatory
    cvDestroyWindow(argv[1]);

    cvDestroyWindow("Componente GREEN");

    return EXIT_SUCCESS;
}
