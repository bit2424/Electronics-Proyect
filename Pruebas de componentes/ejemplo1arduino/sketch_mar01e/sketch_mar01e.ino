int ledPin = 9;
int sensorPin = A3;
float sensorValue = 0;

void setup() {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    pinMode(sensorPin, INPUT);
}

void loop() {
  for(int a = 0;a<255;a++){
    Serial.print("El valor analogo es: ");
    digitalWrite(ledPin,HIGH);
    }for(int a = 255;a>1;a--){
      analog
      }
  
  sensorValue = analogRead(sensorPin);
  if(((sensorValue/1023)*5)>2.5){
    Serial.print("El valor analogo es: ");
    digitalWrite(ledPin,HIGH);
    }else{
      Serial.print("El valor analogo es: ");
    digitalWrite(ledPin,LOW);
      }
  Serial.println((sensorValue/1023)*5);
  delay(100);
  
}
