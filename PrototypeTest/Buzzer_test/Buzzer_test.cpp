#include<wiringPi.h>
#include<stdio.h>
#define Buzzer 0

int main(void){
    if(wiringPiSetup()==-1){
        printf("setup wiringPi failed!");
        return 1;
    }
    pinMode(Buzzer,OUTPUT);
    while(1){
        digitalWrite(Buzzer,HIGH);
        delay(1000);
        digitalWrite(Buzzer,LOW);
        delay(1000);
    }
    return 0;
}
