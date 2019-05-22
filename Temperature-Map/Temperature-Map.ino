#include <UTFT.h>

#include <Servo.h>

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int temperatura = 1700;


Servo myservo1;
Servo myservo2;

int laser = 13;

// Declare which fonts we will be using
extern uint8_t SmallFont[];

int colums = 0;
boolean up = false;
int posI1 = 80;
int posI2 = 60;

UTFT myGLCD(ITDB18SP,7,8,9,5,6);// Remember to change the model parameter to suit your display module!


void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  mlx.begin(); 
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();
  myservo1.attach(4);
  myservo2.attach(3);
  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);
}



void loop() {
  myGLCD.setColor(0,0,0);
  //myGLCD.fillRect(1,14,158,113);
  
  colums++;
  if(colums>95){
    colums = 0;
  }
  for (int i=0; i<120; i++){
    double val = mlx.readObjectTempC();
    Serial.print("*C\tObject = "); Serial.print(val); Serial.println("*C");
    //red green blue
    temperatura = map(val,-50,270,1700,10000);
    myservo1.write(i);
    
    int red = dRed(val);
    int blue = dBlue(val);
    int green = dGreen(val);
    
    myGLCD.setColor( red, blue , green);
    myGLCD.drawPixel(2+i, 16+colums);

    if(up){
      myservo2.write(posI2+i);
    }else{
      myservo2.write(posI2+100-i);
    }
        
    delay(10);
  }

  if(up){
    up =false;
  }else{
    up = true;
  }

  myservo1.write(posI1+colums);
}


int dRed(int temp){
  return 0;
}

int dBlue(int temp){
  return 0;
}

int dGreen(int temp){
  return 0;
}
