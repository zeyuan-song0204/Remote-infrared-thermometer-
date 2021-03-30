#include<wiringPi.h>
#include<stdio.h>
#define RED 25
#define YELLOW  24
#define GREEN 23
int main(void){
    int t;
    if(wiringPiSetup()==-1){
        printf("setup wiringPi failed!");
        return 1;
    }
    pinMode(RED,OUTPUT);
    pinMode(YELLOW,OUTPUT);
    pinMode(GREEN,OUTPUT);
    while(1){
        t=1;
        if(t==1){
            printf("red on\n");
            digitalWrite(RED,HIGH);
            digitalWrite(YELLOW,LOW);
            digitalWrite(GREEN,LOW);
            delay(2000);
            t=2;
        }
        if(t==2){
            printf("yellow on\n");
            digitalWrite(RED,LOW);
            digitalWrite(YELLOW,HIGH);
            digitalWrite(GREEN,LOW);
            delay(2000);
            t=3;
        }
        if(t==3){
            printf("green on\n");
            digitalWrite(RED,LOW);
            digitalWrite(YELLOW,LOW);
            digitalWrite(GREEN,HIGH);
            delay(2000);
            t=1;
        }
        
    }
    return 0;
}
//gcc -o led led.cpp -lwiringPi
