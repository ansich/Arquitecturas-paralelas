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
 IplImage* ImgBLUE = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);

 int fila1, columna1;

 for (fila1 = 0; fila1 < Img->height; fila1++) {

 unsigned char *pImg = (unsigned char *) Img->imageData + fila1 * Img->
widthStep;
 unsigned char *pImgBLUE = (unsigned char *) ImgBLUE->imageData + fila1 *
ImgBLUE->widthStep;

 for (columna1 = 0; columna1 < Img->width; columna1++) {

 //Imagen BLUE
 *pImgBLUE++ = *pImg++;
 *pImgBLUE++ = 0;
 pImg++;
 *pImgBLUE++ = 0;
 pImg++;
 }
 }
// Crea la imagen para la componete rojo
 
 IplImage* ImgRED = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);

 int fila2, columna2;

 for (fila2 = 0; fila2 < Img->height; fila2++) {

 unsigned char *pImg2 = (unsigned char *) Img->imageData + fila2 * Img->
widthStep;
 unsigned char *pImgRED = (unsigned char *) ImgRED->imageData + fila2 *
ImgRED->widthStep;

 for (columna2 = 0; columna2 < Img->width; columna2++) {

 //Imagen RED
 *pImgRED++ = 0;
 pImg2++;
 *pImgRED++ = 0;
 pImg2++;
 *pImgRED++ = *pImg2++;
 }
 }
 // Crea la imagen para la componete verde
 
 IplImage* ImgGREEN = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);

 int fila3, columna3;

 for (fila3 = 0; fila3 < Img->height; fila3++) {

 unsigned char *pImg3 = (unsigned char *) Img->imageData + fila3 * Img->
widthStep;
 unsigned char *pImgGREEN = (unsigned char *) ImgGREEN->imageData + fila3 *
ImgGREEN->widthStep;

 for (columna3 = 0; columna3 < Img->width; columna3++) {

 //Imagen RED
 *pImgGREEN++ = 0;
 pImg3++;
 *pImgGREEN++ = *pImg3++;
  *pImgGREEN++ = 0;
  pImg3++;
 }
 }
 
// fin ejercicio 2
 
 // crea y muestras las ventanas con las imagenes
 cvNamedWindow("Componente BLUE", CV_WINDOW_AUTOSIZE);
cvShowImage("Componente BLUE", ImgBLUE);
cvWaitKey(3000);
 cvNamedWindow("Componente RED", CV_WINDOW_AUTOSIZE);
cvShowImage("Componente RED", ImgRED);
cvWaitKey(3000);
 cvNamedWindow("Componente GREEN", CV_WINDOW_AUTOSIZE);
cvShowImage("Componente GREEN", ImgGREEN);
cvWaitKey(3000);

 

 // memory release for images before exiting the application
 cvReleaseImage(&Img);
 cvReleaseImage(&ImgBLUE);
// cvReleaseImage(&Img);
 cvReleaseImage(&ImgRED);
 cvReleaseImage(&ImgGREEN);
 // Self-explanatory
 cvDestroyWindow(argv[1]);
 cvDestroyWindow("Componente BLUE");
 cvDestroyWindow("Componente RED");
 cvDestroyWindow("Componente GREEN");

 return EXIT_SUCCESS;
 }