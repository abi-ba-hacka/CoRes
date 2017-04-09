#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
SoftwareSerial bt(9, 13);

int i = 0;
int j = 0;
int pinBoton = 8;
int canilla_habilitada = 0;
char c = 2;
int estadoBoton=0;
byte customchar [8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
  };



void setup() {
  
  bt.begin(9600);
  Serial.begin(38200);

  pinMode(6,OUTPUT);  //CORRESPONDE AL ASCII "0"
  pinMode(7,OUTPUT);  //CORRESPONDE AL ASCII "1"
  lcd.begin(20,4);
  pinMode(pinBoton, INPUT);
  lcd.clear();
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
 
}

void loop() {

//digitalWrite(6,HIGH);
if(bt.available())
{
c=bt.read();
Serial.write(c);
estadoBoton = digitalRead(pinBoton);
if (c == '1' && estadoBoton == HIGH )
    {
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
     // delay(5000);
      for(i=0;i<20;i++)
            {
              lcd.createChar(1, customchar);
              lcd.setCursor(i,j);
              lcd.write(1);
              lcd.setCursor(i,j+1);
              lcd.write(1);
              lcd.setCursor(i,j+2);
              lcd.write(1);
              lcd.setCursor(i,j+3);
              lcd.write(1);
              delay(400);
            }
      delay(500);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      lcd.clear();
      }
else if(c == '2' && estadoBoton == LOW)
    {
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      delay(300);
      lcd.clear();
    }


}
}

