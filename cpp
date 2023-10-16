// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:Filters
// Last Modification Date:10/10/2023
// Toqa Abdalla Ahmed         id:20220093      email:abdallatoqa56@gmail.com
//habiba alaa eldin mahfouz   id : 20220104    email:habibaalaa775@gmail.com
//kermina nashaat shafiek     id:  20220255    email:knashaat544@gmail.com

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char imageR[SIZE][SIZE];
unsigned char secondImage[SIZE][SIZE];
unsigned char croppedImage[SIZE][SIZE];
void loadImage();

void saveImage();

void doBW();

void FlipImage();

void doSomethingForImage();

void mergeImages();

void RotateImage();

void invertImage();

void loadImage2();

void Edge();

void blurImage();

void crop();

void MirrorImage();

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
    cout<<"10- Mirror 1/2 image"<<endl;
    cout<<"12- Blur image"<<endl;
    cout << "13-Crop Image" << endl;
    int a;
    cin >> a;
    if (a == 1) {
        doBW();
    } else if (a == 2) {
        invertImage();
    } else if (a == 3) {
        mergeImages();
    } else if (a == 4) {
        FlipImage();
    } else if (a == 5) {
        RotateImage();
    } else if (a == 6) {
        doSomethingForImage();
    } else if (a == 7)
        Edge();
    else if(a==10)
        MirrorImage();
    else if(a==12)
        blurImage();
    else if (a == 13)
        crop();
    else if (a == 0) {
        return 0;
    }

    saveImage();

    return 0;
}

//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void doBW() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {


            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;

        }
    }
}

//--------------------------//2
void invertImage() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 0 && image[i][j] < 255)//grey int opp
                image[i][j] = 255 - image[i][j];
            else if (image[i][j] == 0) { //black into white
                image[i][j] = 255;
            }
        }
    }
}

void FlipImage() {
    cout << "Flip the image (h)orizontally or (v)ertically?\n";
    char ans;
    cin >> ans;
    unsigned char image2[SIZE][SIZE];
    if (ans == 'v') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j];
                image[i][j] = image[SIZE - i - 1][j]; // Flip vertically
                image[SIZE - i - 1][j] = image2[i][j];
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image2[i][j] = image[i][j];
                image[i][j] = image[i][SIZE - j - 1];
                image[i][SIZE - j - 1] = image2[i][j];
            }
        }
    }
}

//-------------------------//5 rotate image
void RotateImage() {
    //rotate
    int deg;
    cout << "Rotate (90) or (180) or (270) ?";
    cin >> deg;
    if (deg == 90) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageR[i][j] = image[SIZE - 1 - j][i];
            }
        }
    } else if (deg == 180) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageR[i][j] = image[SIZE - 1 - i][SIZE - 1 - j];
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageR[i][j] = image[j][SIZE - 1 - i];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = imageR[i][j];

        }
    }
}


//-------------------------------------------------
void loadImage2() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter name image file to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, secondImage);
}

void mergeImages() {
    loadImage2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            unsigned char gray1 = image[i][j];
            unsigned char gray2 = secondImage[i][j];
            unsigned char averageGray = (gray1 + gray2) / 2;
            image[i][j] = averageGray;
        }
    }
}

//-------------------------------------------------------------

void doSomethingForImage() {
    char choose;
    cout << "Do you want to lighten (L) or darken (D) the image? ";
    cin >> choose;

    unsigned char pixel;
    unsigned char modifiedPixel;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pixel = image[i][j];

            if (choose == 'L' || choose == 'l') {
                // Lighten the pixel by 50%
                modifiedPixel = pixel + (255 - pixel) / 2;
            } else if (choose == 'D' || choose == 'd') {
                // Darken the pixel by 50%
                modifiedPixel = pixel / 2;
            } else {
                cout << "Invalid choice. Exiting without modification." << endl;
                return;
            }

            image[i][j] = modifiedPixel;
        }
    }
}

//------------------------------------------------------------

void Edge() {
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            if (abs(image[i][j] - image[i - 1][j]) > 35 && abs(image[i][j] - image[i + 1][j]) > 35) {
                image[i][j] = 0;
            } else if (abs(image[i][j] - image[i][j - 1]) > 35 && abs(image[i][j] - image[i][j + 1]) > 35)
                image[i][j] = 0;
            else
                image[i][j] = 255;
        }
    }
}

//-------------------------------------------------------------

void blurImage()
{
    unsigned char newImage[ORIGINAL_SIZE][ORIGINAL_SIZE];

    for (int i = 0; i < ORIGINAL_SIZE; i++)
    {
        for (int j = 0; j < ORIGINAL_SIZE; j++)
        {
            // Calculate average value of surrounding pixels
            int sum = 0;
            int count = 0;

            // Increase the size of the neighborhood to achieve stronger blur
            for (int x = -2; x <= 2; x++)
            {
                for (int y = -2; y <= 2; y++)
                {
                    int row = i + x;
                    int col = j + y;

                    if (row >= 0 && row < ORIGINAL_SIZE && col >= 0 && col < ORIGINAL_SIZE)
                    {
                        sum += originalImage[row][col];
                        count++;
                    }
                }
            }

            newImage[i][j] = static_cast<unsigned char>(sum / count);
        }
    }

    memcpy(originalImage, newImage, ORIGINAL_SIZE * ORIGINAL_SIZE * sizeof(unsigned char));
}

//---------------------------------------------------------

void crop() {
    int x, y, l, w;
    cout << "Please enter x,y,l,w" << endl;
    cin >> x >> y >> l >> w;
        for (int i = y; i < y + w; i++) {
            for (int j = x; j < x + l; j++) {
                croppedImage[i][j] = image[i][j];
            }
        }
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j]=255;
                for (int i = y; i < y + w; i++) {
                    for (int j = x; j < x + l; j++) {
                        image[i][j] = croppedImage[i][j];
                    }
                }
            }
        }
}

void MirrorImage(){
    char x;
    cout<<"Mirror (l)eft , (r)ight ,(u)pper , (d)own side?"<<endl;
    cin>>x;
    if(x=='l'){
        for(int i=0;i<SIZE;i++){
            for(int j=(SIZE/2);j<SIZE;j++){
                image[i][j]=image[i][SIZE-j-1];
            }
        }
    }
    else if(x=='r'){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE/2;j++){
                image[i][j]=image[i][SIZE-j-1];
            }
        }
    }
    else if(x=='u'){
        for(int i=SIZE/2;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j]=image[SIZE-i-1][j];
            }
        }
    }
    else if(x=='d'){
        for(int i=0;i<SIZE/2;i++){
            for(int j=0;j<SIZE;j++){
                image[i][j]=image[SIZE-i-1][j];
            }
        }
    }
}
