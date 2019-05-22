int ledPin = 8;
int sensorPin = A3;
float sensorValue = 0;

void setup() {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    pinMode(sensorPin, INPUT);
}

void loop() {
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
