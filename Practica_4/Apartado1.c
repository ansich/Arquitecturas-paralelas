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
   
    // Always check if the program can find a file
    if (!Img1) {
        printf("Error: fichero %s no leido\n", argv[1]);
        return EXIT_FAILURE;
    }
    if (!Img2) {
        printf("Error: fichero %s no leido\n", argv[2]);
        return EXIT_FAILURE;
    }
    
    IplImage* mascara = cvCreateImage(cvSize(Img2->width, Img2->height), IPL_DEPTH_8U, 3);
   
    int fila, columna;
    
    for (fila = 0; fila < Img2->height; fila++) {
        unsigned char *pImg2 = (unsigned char *) Img2->imageData + fila * Img2->
                widthStep;
        unsigned char *pMascara = (unsigned char *) mascara->imageData + fila *
                mascara->widthStep;
        for (columna = 0; columna < Img2->width; columna++) {

            //mascara

            int blue = *pImg2;
            pImg2++;
            int green = *pImg2;
            pImg2++;
            int red = *pImg2;
            pImg2++;
            
            if(blue == 0 && green == 0 && red == 0){
            *pMascara = 255;
            pMascara++;
            *pMascara = 255;
            pMascara++;
            *pMascara = 255;
            pMascara++;
            
            }
            else{
           *pMascara = 0;
            pMascara++;
            *pMascara = 0;
            pMascara++;
            *pMascara = 0;
            pMascara++;
            }
        }
    }

   IplImage* streetFighter = cvCloneImage(Img1);
     
   /*int fil, col;
    
    for (fil = 0; fil < Img2->height; fil++) {
        unsigned char *pStreet = (unsigned char *) streetFighter->imageData + fil * streetFighter->
                widthStep;
        unsigned char *pI2 = (unsigned char *) Img2->imageData + fil * Img2->
                widthStep;
        unsigned char *pM = (unsigned char *) mascara->imageData + fil *
                mascara->widthStep;
        
        for (col = 0; col < Img2->width; col++) {
            int blue = *pM;
            pM++;
            pM++;
            pM++;
            
            if(blue == 0){
                *pStreet= *pI2;
                pStreet++;
                pI2++;
                *pStreet= *pI2;
                pStreet++;
                pI2++;
                *pStreet= *pI2;
                pStreet++;
                pI2++;
           }else{
                pStreet=pStreet+3;
                pI2=pI2+3;
            }
        }
    }
   */
   
    int fil, col, rec;
      
     for(rec=0; rec < Img1->width; rec++){
        int aux = (Img1->height - Img2->height) + rec;
        
        for (fil = 0; fil < Img2->height; fil++) {
                unsigned char *pI1 = (unsigned char *) Img1->imageData + (aux + fil) * Img1->
                        widthStep;
                unsigned char *pStreet = (unsigned char *) streetFighter->imageData + (aux + fil) * streetFighter->
                        widthStep;
                unsigned char *pI2 = (unsigned char *) Img2->imageData + fil * Img2->
                        widthStep;
                unsigned char *pM = (unsigned char *) mascara->imageData + fil * mascara->
                        widthStep;
        
        for (col = 0; col < Img2->width; col++) {
            
                *pStreet= ((*pI1 & *pM)|(*pI2 & ~(*pM)));
                pStreet++;
                pI2++;
                pI1++;
                pM++;
                *pStreet= ((*pI1 & *pM)|(*pI2 & ~(*pM)));
                pStreet++;
                pI2++;
                pI1++;
                pM++;
                *pStreet= ((*pI1 & *pM)|(*pI2 & ~(*pM)));
                pStreet++;
                pI2++;
                pI1++;
                pM++;
          
               }
        }
    
    
    cvNamedWindow("mascara", CV_WINDOW_AUTOSIZE);
    cvShowImage("mascara", mascara);
    cvWaitKey(0);
    cvDestroyWindow("mascara");    
        
    cvNamedWindow("animacion", CV_WINDOW_AUTOSIZE);
    cvShowImage("animacion", streetFighter); cvWaitKey(0);}
    cvWaitKey(0);
    cvDestroyWindow("animacion");
    
    
    return (EXIT_SUCCESS);
}
