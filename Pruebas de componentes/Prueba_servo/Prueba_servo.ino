#include <UTFT.h>

#include <Servo.h>

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo myservo1;
Servo myservo2;

int transistor1 = 13;
int transistor2 = 12;
int temperatura = 1700;
int colums = 0;
boolean up = false;
int posI1 = 80;
int posI2 = 60;

void setup() {
  Serial.begin(9600);
  
  myservo1.attach(4);
  myservo2.attach(3);
  pinMode(transistor1, OUTPUT);
  pinMode(transistor2, OUTPUT);
  myservo1.write(60);
}



void loop() {
  
  colums++;
  if(colums>60){
    colums = 0;
  }
  
  for (int i=0; i<100; i++){
    if(up){
      myservo2.write(posI2+i);
    }else{
      myservo2.write(posI2+100-i);
    }
    delay(8);
  }

  if(up){
    up =false;
  }else{
    up = true;
  }

  myservo1.write(posI1+colums);
  delay(5);
  
}

