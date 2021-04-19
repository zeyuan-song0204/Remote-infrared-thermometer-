#include "opencv2/opencv.hpp"
#include<wiringPi.h>
#include<stdio.h>
#include<time.h>
#include<thread>
#include<pthread.h>
#include<iostream>
#include<csignal>
#include<python3.7m/Python.h>

using namespace cv;
using namespace std;

#define Buzzer 0
#define RED 25
#define YELLOW  24
#define GREEN 23
string Path="/home/pi/Piproject/haarcascade_frontalface_default.xml";
//string eye_Path="/home/pi/Piproject/haarcascade_eye_tree_eyeglasses.xml";
//string Path="/home/pi/Piproject/haarcascade_eye.xml";
PyObject* sensor=nullptr;
PyObject* pFunc=nullptr;
PyObject* pModule=nullptr;
PyObject* board=nullptr;
PyObject* I2C_func=nullptr; 
PyObject* i2c=nullptr;
PyObject* AMG88xx=nullptr;
PyObject* xxx=nullptr;
double temperature=0;

void *initGpio_thread(void *args){
    if(wiringPiSetup()==-1){
        printf("setup wiringPi failed!");
    } 
    pinMode(Buzzer,OUTPUT);
    pinMode(RED,OUTPUT);
    pinMode(YELLOW,OUTPUT);
    pinMode(GREEN,OUTPUT);
    printf("InitGpio successed(thread)\n");
    return(void *)0;
}
void *Buzzer_thread(void *args){
    if(temperature>=38){
        //warning
        for(int i=0;i<10;i++){
            digitalWrite(Buzzer,HIGH);
            delay(100);
            digitalWrite(Buzzer,LOW);
            delay(100);
            }
        }else{
            digitalWrite(Buzzer,HIGH);
            delay(1000);
            digitalWrite(Buzzer,LOW);
            delay(1000);
        }
    return(void *)0;
        
}
void *Led_thread(void *args){
    if(temperature>37.5){
        //warning
        printf("Warning\n");
        digitalWrite(GREEN,LOW);
        digitalWrite(RED,HIGH);
        digitalWrite(YELLOW,LOW);
        }else{
            digitalWrite(GREEN,HIGH);
            digitalWrite(RED,LOW);
            digitalWrite(YELLOW,LOW);
        }
    return(void *)0;
}
void offLed(){
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(YELLOW,LOW);
}
double getTemp(int row_po,int col_po){
    PyObject *pixels=PyObject_GetAttrString(sensor,"pixels");
    PyObject *row=PyList_GetItem(pixels,row_po);
    PyObject *tem=PyList_GetItem(row,row_po);
    return PyFloat_AsDouble(tem);
}
void *Call_Python(void *args){
    while(1){
        Py_Initialize();
        if(Py_IsInitialized()){
            //PyRun_SimpleString("print('PyisInitialized')"); 
            pModule=PyImport_ImportModule("adafruit_amg88xx");
            if(pModule){
                //cout<<pModule<<endl;
                board=PyImport_ImportModule("board");
                I2C_func=PyObject_GetAttrString(board,"I2C");
                i2c=_PyObject_CallNoArg(I2C_func);
                AMG88xx=PyObject_GetAttrString(pModule,"AMG88XX");
                xxx=PyTuple_New(1);           
                PyTuple_SetItem(xxx,0,i2c);
                sensor=PyObject_Call(AMG88xx,xxx,NULL);
                double tem =getTemp(4,4);
                //cout<<tem<<endl;
                temperature=tem;
                if(temperature==0){
                    ;
                }else{
                    cout<<temperature+5.5<<endl;
                }
                delay(1000);
            }else{
                printf("import python module failed \n");
            }
        }
        Py_Finalize();
    }
    
    
   }
/*void GreenOn(){  
    printf("green on\n");
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(YELLOW,LOW);
    //rectangle(frame,eyes[t],Scalar(0,0,255),2,8);
    //putText(frame, "Hello", cv::print(200,200), &font, Scalar(255, 0, 0));
}
void RedOn_Signal(int signal){
    printf("Warning\n");
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,HIGH);
    digitalWrite(YELLOW,LOW);
}
void Buzzer_warning(){
    for(int i=0;i<10;i++){
        digitalWrite(Buzzer,HIGH);
        delay(10);
        digitalWrite(Buzzer,LOW);
        delay(10);
    }
}

void Buzzer_testing(){
    digitalWrite(Buzzer,HIGH);
    delay(200);
    digitalWrite(Buzzer,LOW);
    delay(200);
}*/
int main()
{
    pthread_t th_init;
    pthread_t th_buzzer;
    pthread_t th_led;
    pthread_t th_amg;
    std::thread thread_offLed(offLed);
    //std::thread thread_test(Call_Python);
    int init=pthread_create(&th_init,NULL,initGpio_thread,NULL);
    if(init!=0){
        std::cout<<"threadInit create error"<<std::endl;
    }
    
    int amg=pthread_create(&th_amg,NULL,Call_Python,NULL);
    if(th_amg==0){
        std::cout<<"threadAmg create error"<<std::endl;
    }
    
    //std::thread thread_init(initGpio);
    

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

    /*CascadeClassifier eye_Classifier;
    eye_Classifier.load(eye_Path);
    if(!eye_Classifier.load(eye_Path))
    {
        cout<<"eye_Classifier loading failed"<<endl;
        return -1;
    }*/
    
    //cv::Font  font;
    //cv::InitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0, 1.0);

    //thread_init.join();
    //thread_offLed.join();
    //thread_test.join();
    vector<Rect> faces;
    vector<Rect> eyes;

    for(;;)
    {
        Mat frame;
        cap >> frame; 
        Classifier.detectMultiScale(frame,faces,1.1,3,0,Size(30,30));
        //eye_Classifier.detectMultiScale(frame,eyes,1.1,3,0,Size(15,15));
        digitalWrite(YELLOW,HIGH);
        digitalWrite(GREEN,LOW);
        //printf("testing\n");
        for(size_t t=0;t<faces.size();t++)
        {
            rectangle(frame,faces[t],Scalar(0,255,0),2,8);
            int led=pthread_create(&th_led,NULL,Led_thread,NULL);
            if(th_led==0){
                std::cout<<"threadLed create error"<<std::endl;
            }
            
            
            int buzzer=pthread_create(&th_buzzer,NULL,Buzzer_thread,NULL);
            if(th_buzzer==0){
                std::cout<<"threadBuzzer create error"<<std::endl;
            }
            
            //Call_Python();
            /*if(temperature>=38){
                //raise(SIGILL);
                printf("Warning\n");
                digitalWrite(GREEN,LOW);
                digitalWrite(RED,HIGH);
                digitalWrite(YELLOW,LOW);
                Buzzer_warning();
            }else{
                //raise(SIGINT);
                //printf("green on\n");
                digitalWrite(GREEN,HIGH);
                digitalWrite(RED,LOW);
                digitalWrite(YELLOW,LOW);
                //Buzzer_testing();
                Buzzer_testing();
            }*/
        }

        imshow("face detector", frame);
        if(waitKey(30) >= 0) break;
    }
    offLed();
    return 0;
}
