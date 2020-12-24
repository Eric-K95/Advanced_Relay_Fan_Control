//Project: Relay + Fan + MQ2 chemical gas sensor
//Sketched by JIN-WOO KIM

#include <LiquidCrystal_I2C.h>
#include<math.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int mq2Pin = A0; //gas chemical sensor
int ledPin1 = 13; //red led light
int ledPin2 = 12; //blue led light
int buzzerPin = 8; //buzzer
const int relayPin = 2; //relay

void setup() {
  pinMode(relayPin, OUTPUT); //initialize the replay Pin as an output
  pinMode(ledPin1, OUTPUT); //initialize the LED Pin as an output
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT); //initialize the buzzer Pin as an output
  pinMode(mq2Pin, INPUT); //initialize the MQ2 gas chemical sensor as an input
  lcd.begin();
  lcd.setCursor(0, 0); //first column, row #1
  lcd.print("Hello World!");
  delay(2000);   //delay of the message
  lcd.clear();   // clear screen
  lcd.setCursor(0, 0); //first column, row #1
  lcd.print("ST:");
  Serial.begin(9600);
}
void loop() {
  int gas = analogRead(mq2Pin);
  Serial.print("gas_LV: ");
  Serial.println(gas);


  //Set the range of the gas
  if (gas > 600) {
    digitalWrite(relayPin, LOW);
    delay(1000);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    tone(buzzerPin, 300,100);
    lcd.setCursor(3,0);
    lcd.print(" Chemicals    ");
    lcd.setCursor(3,1);
    lcd.print(" Detected!    ");
  }
  else {
    digitalWrite(relayPin, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    noTone(buzzerPin);
    lcd.setCursor(3,0);
    lcd.print("No Chemicals ");
    lcd.setCursor(3,1);
    lcd.print("detected     ");
  }
  delay(100);
}
