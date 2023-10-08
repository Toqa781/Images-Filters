// Toqa Abdalla Ahmed   id:20220093    email:abdallatoqa56@gmail.com

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];


void loadImage ();
void saveImage ();
void doBW ();
void FlipImage();
void Mirror();


int main()
{
  loadImage();
  cout<<"Please select a filter to apply or 0 to exit"<<endl;
  cout<<"1- Black & White Filter"<<endl;
    cout<<"2- Invert Filter"<<endl;
    cout<<"3-Merge Filter"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5- Darken and Lighten Image"<<endl;
    cout<<"6-Rotate Image"<<endl;
    int a;
    cin>>a;
    if(a==1){
        doBW();
    }
    else if(a==2){

    }
    else if(a==3){

    }
    else if(a==4){
        FlipImage();
    }
    else if(a==5){

    }
    else if(a==6){

    }
    else if(a==0){
        return 0;
    }
  saveImage();

  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void doBW() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {


        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;

    }
  }
}
void FlipImage() {
    cout<<"Flip the image (h)orizontally or (v)ertically?\n";
    char ans;
    cin>>ans;
    unsigned char image2[SIZE][SIZE];
    if(ans=='v') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j];
                image[i][j] = image[SIZE - i - 1][j]; // Flip vertically
                image[SIZE - i - 1][j] = image2[i][j];
            }
        }
    }
    else{
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                image2[i][j] = image[i][j];
                image[i][j] = image[i][SIZE-j-1];
                image[i][SIZE-j-1] = image2[i][j];
            }
        }
    }
}






