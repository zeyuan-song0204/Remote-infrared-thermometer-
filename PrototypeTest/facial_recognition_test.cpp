#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

string Path="/home/pi/test/haarcascade_frontalface_default.xml";
//string Path="/home/pi/test/haarcascade_eye.xml";
//string Path="/home/pi/test/haarcascade_eye_tree_eyeglasses.xml";

int main()
{
    VideoCapture cap(0); 
    if(!cap.isOpened())  
    {
        cout<<"camera getting failed"<<endl;
        return -1;
    }
    //定义分类器
    CascadeClassifier Classifier;
    Classifier.load(Path);
    if(!Classifier.load(Path))
    {
        cout<<"Classifier loading failed"<<endl;
        return -1;
    }

    vector<Rect> faces;
    for(;;)
    {
        Mat frame;
        cap >> frame; 
        Classifier.detectMultiScale(frame,faces,1.1,3,0,Size(30,30));
        for(size_t t=0;t<faces.size();t++)
        {
            rectangle(frame,faces[t],Scalar(0,255,0),2,8);
        }

        

        imshow("CAM", frame);
        if(waitKey(30) >= 0) break;
    }
    return 0;
}
