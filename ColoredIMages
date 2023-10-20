// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:Filters
// Last Modification Date:20/10/2023
// s7,s8,s21
// Toqa Abdalla Ahmed         id:20220093      email:abdallatoqa56@gmail.com
//habiba alaa eldin mahfouz   id : 20220104    email:habibaalaa775@gmail.com
//kermina nashaat shafiek     id:  20220255    email:knashaat544@gmail.com

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char RGB_image[SIZE][SIZE][3];
unsigned char RGB_image2[SIZE][SIZE][3];
unsigned char merged_Images[SIZE][SIZE][3];
unsigned char imageE[SIZE][SIZE][3];
unsigned char imageS[SIZE][SIZE][3];
unsigned char imageR[SIZE][SIZE][3];

void loadImage();
void saveImage();
void doBW();
void mergeImages();
void FlipImage();
void RotateImage();
void Enlarge_Image();
void Shuffle_Image();
void invert();
void doSomethingForImage();
void Edge();
void shrink();
void MirrorImage();
void blurImage();
void crop();
void skewVertically();
void skewHorizontally();
void loadImage2();


int main() {
    loadImage();
    cout << "Please select a filter to apply or 0 to exit" << endl;
    cout << "1- Black & White Filter" << endl;
    cout << "2- Invert Filter" << endl;
    cout << "3-Merge Filter" << endl;
    cout << "4-Flip Image" << endl;
    cout << "5-Rotate Image " << endl;
    cout << "6-Darken and Lighten Image" << endl;
    cout << "7-Detect Image Edges" << endl;
    cout << "8-enlarge image" << endl;
    cout << "9-shrink Image" << endl;
    cout << "10- Mirror 1/2 image" << endl;
    cout<<"11- shuffle image"<< endl;
    cout<<"12-Blur image"<<endl;
    cout << "13-Crop Image" << endl;
    cout<<"14-Skew image Vertically"<<endl;
    cout<<"15-Skew image Horizontally"<<endl;
    int a;
    cin >> a;
    if (a == 1) {
        doBW();
    }
    else if(a==2)
        invert();
    else if(a==3)
        mergeImages();
    else if(a==4){
        FlipImage();
    }
    else if(a==5)
        RotateImage();
    else if(a==6)
        doSomethingForImage();
    else if(a==7)
        Edge();
    else if(a==8)
        Enlarge_Image();
    else if(a==9)
        shrink();
    else if(a==10)
        MirrorImage();
    else if(a==11)
        Shuffle_Image();
    else if(a==12)
        blurImage();
    else if(a==13){
        crop();
    }
    else if(a==14){
        skewVertically();
    }
    else if(a==15){
        skewHorizontally();
    }

    saveImage();

    return 0;
}

//_______________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, RGB_image);
}

//_______________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, RGB_image);
}

//_______________1-black and white
void doBW() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (RGB_image[i][j][0] + RGB_image[i][j][1] + RGB_image[i][j][2] / 3 > 127) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            } else {
                RGB_image[i][j][0] = 0;
                RGB_image[i][j][1] = 0;
                RGB_image[i][j][2] = 0;
            }

        }
    }
}
//-------------------------------------------------------------------3-merge Image
void loadImage2(){
    char imageFileName2[100];
    // Get second image file name
    cout << "Enter the second image file name: ";
    cin >> imageFileName2;
    strcat(imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, RGB_image2);
}


void mergeImages()
{
    loadImage2();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                merged_Images[i][j][k] = (RGB_image[i][j][k] + RGB_image2[i][j][k]) / 2;
            }
        }
    }
}
//-------------------------------------------------------------------4-flip Image
void FlipImage() {
    cout << "Flip the image (h)orizontally or (v)ertically?\n";
    char ans;
    cin >> ans;
    unsigned char image2[SIZE][SIZE][3];
    if (ans == 'v') {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image2[i][j][k] = RGB_image[i][j][k];
                    RGB_image[i][j][k] = RGB_image[SIZE - i - 1][j][k]; // Flip vertically
                    RGB_image[SIZE - i - 1][j][k] = image2[i][j][k];
                }
            }
        }
    }
    else if(ans=='h'){
        for(int k=0;k<3;k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image2[i][j][k] = RGB_image[i][j][k];
                    RGB_image[i][j][k] = RGB_image[i][SIZE - j - 1][k];
                    RGB_image[i][SIZE - j - 1][k] = image2[i][j][k];
                }
            }
        }

    }
}
//___
void invert(){
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                RGB_image[i][j][k]=255-RGB_image[i][j][k];
            }

        }

    }

}
//-------------------------------------------------------6-lighten abd darken
void doSomethingForImage()
{
    char choose;
    cout << "Do you want to lighten (L) or darken (D) the image? ";
    cin >> choose;

    unsigned char pixel;
    unsigned char modifiedPixel;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                pixel = RGB_image[i][j][k];

                if (choose == 'L' || choose == 'l')
                {
                    // Lighten the pixel by 50%
                    modifiedPixel = pixel + (255 - pixel) / 2;
                }
                else if (choose == 'D' || choose == 'd')
                {
                    // Darken the pixel by 50%
                    modifiedPixel = pixel / 2;
                }
                else
                {
                    cout << "Invalid choice. Exiting without modification." << endl;
                    return;
                }

                RGB_image[i][j][k] = modifiedPixel;
            }
        }
    }
}
//________________________
void RotateImage(){
    //rotate
    int deg;
    cout << "Rotate (90) or (180) or (270) ?";
    cin >> deg;
    if (deg == 90) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    imageR[i][j][k] = RGB_image[SIZE - 1 - j][i][k];
                }
            }
        }
    }
    else if (deg == 180) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    imageR[i][j][k] = RGB_image[SIZE - 1 - i][SIZE - 1 - j][k];
                }
            }
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    imageR[i][j][k] = RGB_image[j][SIZE - 1 - i][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                RGB_image[i][j][k] = imageR[i][j][k];

            }
        }
    }
}
//-----------------------------------------------------7- detect edges
void Edge() {
    for (int k = 0; k < 3; k++) {
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                if (abs(RGB_image[i][j][k] - RGB_image[i - 1][j][k]) > 30 &&
                    abs(RGB_image[i][j][k] - RGB_image[i + 1][j][k]) > 30) {
                    RGB_image[i][j][k] = 0;
                } else if (abs(RGB_image[i][j][k] - RGB_image[i][j - 1][k]) > 30 &&
                           abs(RGB_image[i][j][k] - RGB_image[i][j + 1][k]) > 30)
                    RGB_image[i][j][k] = 0;
                else {
                    RGB_image[i][j][0] = 255;
                    RGB_image[i][j][1] = 255;
                    RGB_image[i][j][2] = 255;
                }
            }
        }
    }
}

//-------------------------------------9-shrinkImage
void shrink() {
    cout << "Shrink to (1/2), (1/3) or (1/4)?: ";
    string choice;
    cin >> choice;
    if (choice == "1/2") {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                RGB_image[i][j][0] = (RGB_image[i * 2][j * 2][0]);
                RGB_image[i][j][1] = (RGB_image[i * 2][j * 2][1]);
                RGB_image[i][j][2] = (RGB_image[i * 2][j * 2][2]);
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
    } else if (choice == "1/3") {
        for (int i = 0; i < SIZE / 3; i++) {
            for (int j = 0; j < SIZE / 3; j++) {
                RGB_image[i][j][0] = (RGB_image[i * 3][j * 3][0]);
                RGB_image[i][j][1] = (RGB_image[i * 3][j * 3][1]);
                RGB_image[i][j][2] = (RGB_image[i * 3][j * 3][2]);
            }
        }
        for (int i = SIZE / 3; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
        for (int i = 0; i < SIZE / 3; i++) {
            for (int j = SIZE / 3; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
    } else{
        for (int i = 0; i < SIZE / 4; i++) {
            for (int j = 0; j < SIZE / 4; j++) {
                RGB_image[i][j][0] = (RGB_image[i * 4][j * 4][0]);
                RGB_image[i][j][1] = (RGB_image[i * 4][j * 4][1]);
                RGB_image[i][j][2] = (RGB_image[i * 4][j * 4][2]);
            }
        }
        for (int i = SIZE / 4; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
        for (int i = 0; i < SIZE / 4; i++) {
            for (int j = SIZE / 4; j < SIZE; j++) {
                RGB_image[i][j][0] = 255;
                RGB_image[i][j][1] = 255;
                RGB_image[i][j][2] = 255;
            }
        }
    }
}
//-------------------------------------------
void Shuffle_Image() {
    unsigned char image2[SIZE][SIZE][3];
    unsigned char image3[SIZE][SIZE][3];
    unsigned char origin[SIZE][SIZE][3];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {

                origin[i][j][k] = RGB_image[i][j][k];
                image3[i][j][k] = RGB_image[i][j][k];
                image2[i][j][k] = RGB_image[i][j][k];
            }
        }
    }
    cout << "Enter the image new order :";
    int arr[4];
    for (int i = 0; i < 4; ++i) {
        cin >> arr[i];
    }
    if (arr[0] == 1) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j][k] = origin[i][j][k];
                }
            }
        }
    } else if (arr[0] == 2) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j][k] = origin[i][j + 128][k];
                }
            }
        }
    } else if (arr[0] == 3) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j][k] = origin[i + 128][j][k];
                }
            }
        }
    } else if (arr[0] == 4) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j][k] = origin[i + 128][j + 128][k];
                }
            }
        }
    }
    if (arr[1] == 1) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j + 128][k] = origin[i][j][k];
                }
            }
        }
    } else if (arr[1] == 2) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j + 127][k] = origin[i][j + 127][k];
                }
            }
        }
    } else if (arr[1] == 3) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j + 127][k] = origin[i + 127][j][k];
                }
            }
        }
    } else if (arr[1] == 4) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i][j + 127][k] = origin[i + 127][j + 127][k];
                }
            }
        }
    }
    if (arr[2] == 1) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[127 + i][j][k] = origin[i][j][k];
                }
            }
        }
    } else if (arr[2] == 2) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[127 + i][j][k] = origin[i][127 + j][k];
                }
            }
        }

    } else if (arr[2] == 3) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[128+ i][j][k] = origin[i + 128][j][k];
                }
            }
        }
    } else if (arr[2] == 4) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[128 + i][j][k] = origin[128 + i][128 + j][k];
                }
            }
        }
    }
    if (arr[3] == 1) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i + 128][j + 128][k] = origin[i][j][k];
                }
            }
        }
    } else if (arr[3] == 2) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i + 128][j + 128][k] = origin[i][j + 128][k];
                }
            }
        }
    } else if (arr[3] == 3) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i + 128][j + 128][k] = origin[i + 128][j][k];
                }
            }
        }
    } else if (arr[3] == 4) {
        for (int i = 0; i < SIZE / 2; ++i) {
            for (int j = 0; j < SIZE / 2; ++j) {
                for (int k = 0; k < 3; ++k) {

                    RGB_image[i + 128][j + 128][k] = origin[i + 128][j + 128][k];
                }
            }
        }
    }
}
//________10-mirror image
void MirrorImage() {
    char x;
    cout << "Mirror (l)eft , (r)ight ,(u)pper , (d)own side?" << endl;
    cin >> x;
    if (x == 'l') {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = (SIZE / 2); j < SIZE; j++) {
                    RGB_image[i][j][k] = RGB_image[i][SIZE - j - 1][k];
                }
            }
        }
    } else if (x == 'r') {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    RGB_image[i][j][k] = RGB_image[i][SIZE - j - 1][k];
                }
            }
        }
    } else if (x == 'u') {
        for (int k = 0; k < 3; k++) {
            for (int i = SIZE / 2; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    RGB_image[i][j][k] = RGB_image[SIZE - i - 1][j][k];
                }
            }
        }
    } else if (x == 'd') {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    RGB_image[i][j][k] = RGB_image[SIZE - i - 1][j][k];
                }
            }
        }
    }
}
//-----------------------------------------------------12-blur image
void blurImage() {
    unsigned char newImage[SIZE][SIZE][3];
    for (int i = 0; i < SIZE ;i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int  k= 0; k < 3; k++) {
                // Calculate average value of surrounding pixels
                int sum = 0;
                int count = 0;
                // Increase the size of the neighborhood to achieve stronger blur
                for (int x = -2; x <= 2; x++) {
                    for (int y = -2; y <= 2; y++) {
                        int row = i + x;
                        int col = j + y;
                        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                            sum += RGB_image[row][col][k];
                            count++;
                        }
                    }
                }
                newImage[i][j][k] = static_cast<unsigned char>(sum / count);
            }
        }
    }
    memcpy(RGB_image, newImage, SIZE * SIZE * 3 * sizeof(unsigned char));
}
//_________

void Enlarge_Image(){
    int part;
    cout<<"wich part do you want to enlarge 1 , 2 , 3 or 4:";
    cin>>part;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k< 3; k++){
                //setting image2 to be white
                imageE[i][j][k] = 255;
            }
        }
    }
    if(part == 1){

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE ; ++j) {
                for (int k = 0; k< 3; k++){
                    imageE[i][j][k] = RGB_image[i/2][j/2][k/2];
                }
            }
        }

    }
    else if(part == 2){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k< 3; k++){
                    imageE[i][j][k]= RGB_image[i/2][(j+256)/2][k/2];
                }
            }
        }}


    else if(part == 3){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k< 3; k++){
                    imageE[i][j][k] = RGB_image[(i+256)/2][j/2][k/2];
                }
            }
        }
    }


    else if(part == 4){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k< 3; k++){
                    imageE[i][j][k] = RGB_image[(i + 256) / 2][(j + 256) / 2][(k+127)/2];
                }
            }
        }}

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k< 3; k++){
                //copying new image to the original one
                RGB_image[i][j][k] = imageE[i][j][k];
            }
        }
    }
}
//-----------------------------------------------------13-crop Image
void crop() {
    int x, y, l, w;
    unsigned char croppedImage[SIZE][SIZE][3];
    cout << "Please enter x,y,l,w" << endl;
    cin >> x >> y >> l >> w;
    for (int k = 0; k < 3; k++) {
        for (int i = y; i < y + w; i++) {
            for (int j = x; j < x + l; j++) {
                croppedImage[i][j][k] = RGB_image[i][j][k];
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                RGB_image[i][j][k] = 255;
                for (int i = y; i < y + w; i++) {
                    for (int j = x; j < x + l; j++) {
                        RGB_image[i][j][k] = croppedImage[i][j][k];
                    }
                }
            }
        }

    }
}
void skewVertically(){

    cout<<"Please enter degree to skew Up: ";
    double rad;
    cin>>rad;
    rad = (rad*22)/(7*180);
    double sk = abs(tan(rad)) * 256;
    double decreaseMoves = sk/256;
    double skip = 1 + (sk/255); //because we use skip in the indexes
    unsigned char skewImage[SIZE+int(sk)][SIZE][3];
    for(int i=0 ; i<SIZE+int(sk)  ; i++){
        for(int j=0 ; j<SIZE; j++){
            skewImage[i][j][0] = 255;
            skewImage[i][j][1] = 255;
            skewImage[i][j][2] = 255;
        }
    }
    for(int j=0 ; j<SIZE ; j++){
        for(int i=0 ; i<SIZE; i++){
            skewImage[i+int(sk)][j][0] = RGB_image[i][j][0];
            skewImage[i+int(sk)][j][1] = RGB_image[i][j][1];
            skewImage[i+int(sk)][j][2] = RGB_image[i][j][2];
        }
        sk -= decreaseMoves ;
    }
    for(int i=0 ; i<SIZE ; i++){
        for(int j=0 ; j<SIZE ; j++){
            RGB_image[i][j][0] = skewImage[int(i*skip)][j][0];
            RGB_image[i][j][1] = skewImage[int(i*skip)][j][1];
            RGB_image[i][j][2] = skewImage[int(i*skip)][j][2];
        }
    }
}
void skewHorizontally(){

    double rad;
    cout<< "please enter the angle: "<<endl;
    cin>> rad;
    rad= 90 - rad;
    rad = (rad *22)/(180*7);
    double x= 256 / (1+(1 / tan(rad)));

    for (int j=0; j<SIZE; ++j){
        for(int i=0; i<SIZE; ++i){
            imageS[j] [(int) (i * x) / SIZE][0] =RGB_image[j][i][0];
            imageS[j] [(int) (i * x) / SIZE][1] =RGB_image[j][i][1];
            imageS[j] [(int) (i * x) / SIZE][2] =RGB_image[j][i][2];
        }
    }
    for(int j=0; j<SIZE; j++){
        for (int i=0;i<SIZE;i++){
            RGB_image[j][i][0]= imageS[j][i][0];
            RGB_image[j][i][1]= imageS[j][i][1];
            RGB_image[j][i][2]= imageS[j][i][2];

            imageS[j][i][0]= 255;
            imageS[j][i][1]= 255;
            imageS[j][i][2]= 255;
        }
    }
    double sk , vt;
    sk = SIZE-x;
    vt = sk / SIZE;
    for(int j=0 ; j < SIZE  ; j++){
        for (int i=(int)sk ; i<sk +x ;i++){
            imageS[j][i][0] = RGB_image[j][(int) (i - sk)][0];
            imageS[j][i][1] = RGB_image[j][(int) (i - sk)][1];
            imageS[j][i][2] = RGB_image[j][(int) (i - sk)][2];
        }
        sk -= vt;
    }
    for(int j =0; j<SIZE; j++ ){
        for (int i = 0;i < SIZE; i++ ){
            RGB_image[j][i][0] = imageS[j][i][0];
            RGB_image[j][i][1] = imageS[j][i][1];
            RGB_image[j][i][2] = imageS[j][i][2];
        }
    }


}
