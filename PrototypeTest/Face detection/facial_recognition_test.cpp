#include "opencv2/opencv.hpp"
#include<wiringPi.h>
#include<stdio.h>
using namespace cv;
using namespace std;

#define RED 25
#define YELLOW  24
#define GREEN 23
string Path="/home/pi/Piproject/haarcascade_frontalface_default.xml";
string eye_Path="/home/pi/Piproject/haarcascade_eye_tree_eyeglasses.xml";
//string Path="/home/pi/Piproject/haarcascade_eye.xml";

int main()
{
    VideoCapture cap(0); 
    if(!cap.isOpened())  
    {
        cout<<"camera getting failed"<<endl;
        return -1;
    }
    
    CascadeClassifier Classifier;
    Classifier.load(Path);
    if(!Classifier.load(Path))
    {
        cout<<"Classifier loading failed"<<endl;
        return -1;
    }

    CascadeClassifier eye_Classifier;
    eye_Classifier.load(eye_Path);
    if(!eye_Classifier.load(eye_Path))
    {
        cout<<"eye_Classifier loading failed"<<endl;
        return -1;
    }
    

    vector<Rect> faces;
    vector<Rect> eyes;
    //cv::Font  font;
    //cv::InitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0, 1.0);

    /*int t;
    if(wiringPiSetup()==-1){
        printf("setup wiringPi failed!");
        return 1;
    }*/
    /*pinMode(RED,OUTPUT);
    pinMode(YELLOW,OUTPUT);
    pinMode(GREEN,OUTPUT);*/
    for(;;)
    {
        Mat frame;
        cap >> frame; 
        Classifier.detectMultiScale(frame,faces,1.1,3,0,Size(30,30));
        //eye_Classifier.detectMultiScale(frame,eyes,1.1,3,0,Size(15,15));
        for(size_t t=0;t<faces.size();t++)
        {
            rectangle(frame,faces[t],Scalar(0,255,0),2,8);
            //rectangle(frame,eyes[t],Scalar(0,0,255),2,8);
            //putText(frame, "Hello", cv::print(200,200), &font, Scalar(255, 0, 0));
            /*digitalWrite(RED,HIGH);
            digitalWrite(YELLOW,LOW);
            digitalWrite(GREEN,LOW);*/
       
        }

        imshow("face detector", frame);
        if(waitKey(30) >= 0) break;
    }
    return 0;
}
