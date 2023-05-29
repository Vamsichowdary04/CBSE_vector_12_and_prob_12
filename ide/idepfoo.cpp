#include <Arduino.h>

//Declaring all variables as integers

int D0,D1,D2,CLK; 
int Q0=0,Q1=0,Q2=0;

//Creating a function

void ref(int D0, int D1, int D2, int CLK) {

      digitalWrite(2,D0);
      digitalWrite(3,D1);
      digitalWrite(4,D2);
      digitalWrite(11,CLK);
}
// the setup function runs once when you press reset or power the board

void setup() {

      pinMode(2,OUTPUT);
      pinMode(3,OUTPUT);
      pinMode(4,OUTPUT);
      pinMode(11,OUTPUT);
      pinMode(6,INPUT);
      pinMode(7,INPUT);
      pinMode(8,INPUT);
}

//the loop function runs over and over again

void loop() {

      digitalWrite(11,HIGH);
      delay(1000);

      Q0=digitalRead (6);                                                                                      
      Q1=digitalRead (7);
      Q2=digitalRead (8);
      D2=(Q1);
      D1=(Q0);                                                                                                 
      D0=!(Q1||Q2);

      digitalWrite(11,LOW);
      ref(D0,D1,D2,CLK);
}
