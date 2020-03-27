#include "RTClib.h"
#include <SPI.h>
#include <SD.h>
RTC_DS3231 rtc;
#include <Wire.h> // La librería Wire.h es para I2C
#include <LiquidCrystal_I2C.h> // La librería para el LCD 16x2 I2C


int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
const int cajon1=8;
const int cajon2=9;
const int cajon3=10;
const int cajon4=11;
const int cajon5=12;

int cajon1H1=9;
int cajon1M1=59;
int cajon1S1=0;
int cajon1H2=14;
int cajon1M2=48;
int cajon1S2=0;

int cajon2H1=9;
int cajon2M1=59;
int cajon2S1=30;
int cajon2H2=14;
int cajon2M2=48;
int cajon2S2=0;

int cajon3H1=9;
int cajon3M1=54;
int cajon3S1=0;
int cajon3H2=14;
int cajon3M2=48;
int cajon3S2=0;

int cajon4H1=9;
int cajon4M1=54;
int cajon4S1=30;
int cajon4H2=14;
int cajon4M2=48;
int cajon4S2=0;

int cajon5H1=9;
int cajon5M1=55;
int cajon5S1=0;
int cajon5H2=14;
int cajon5M2=48;
int cajon5S2=0;


int pito=13;

 LiquidCrystal_I2C lcd(0x27, 16, 2); // Nuestro LCD se comunica en la dirección 27h, e inicializamos la librería para 16x2
   

void pantalla(String pastilla, String numpastilla){



  lcd.setCursor(0, 1);
  lcd.print(pastilla); // Mostramos texto en linea 1
  
 lcd.print(" ");// Mostramos texto en linea 2 (Ubicamos el cursor en la primera posición(columna:0), de la segunda línea(fila:1))
  lcd.print(numpastilla);
  
 

}



void setup() {
   lcd.begin(); //Inicializamos el display 
  lcd.backlight(); // Prendemos el backlight

  Serial.begin(9600);
 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // If the RTC have lost power it will sets the RTC to the date & time this sketch was compiled in the following line
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
  // If you need to set the time of the uncomment line 34 or 37
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
//declaramos el pin amarillo como salida
  pinMode(led1,OUTPUT); 
  pinMode(led2,OUTPUT); 
  pinMode(led3,OUTPUT); 
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(cajon1,INPUT_PULLUP);
  pinMode(cajon2,INPUT_PULLUP);
  pinMode(cajon3,INPUT_PULLUP);
  pinMode(cajon4,INPUT_PULLUP);
  pinMode(cajon5,INPUT_PULLUP);
  pinMode(pito,OUTPUT); 
  
    
    nombre();
    

}

void pantallaoff(){
lcd.begin(); //Inicializamos el display 
lcd.noDisplay();
lcd.begin();


}



void hora(){
 
    lcd.setCursor(5, 0);
  DateTime now = rtc.now();
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    if(now.minute()<10){
      lcd.print("0");
      lcd.print(now.minute(), DEC);
      }
      else{
        lcd.print(now.minute(), DEC);
      }   

    }

void nombre(){
  lcd.setCursor(6, 1);
    lcd.print("SAM"); 
    
  }


void loop() {

  hora();    
   
  DateTime now = rtc.now();
  
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    

    
    //led1 y cajon1
if ((now.hour() == cajon1H1 && now.minute() == cajon1M1 && now.second() == cajon1S1) || (now.hour() == cajon1H2 && now.minute() == cajon1M2 && now.second() == cajon1S2)){
  digitalWrite(led1,HIGH);
  tone(pito, 550);
  pantalla("PARACETAMOL", "4       ");
  Serial.println("el led1 esta encendido");
}
if (digitalRead(cajon1) == 1){
      digitalWrite(led1,LOW); 
      noTone(pito); 
      pantallaoff();
      nombre();
      
      }
      
    //led2 y cajon2
if ((now.hour() == cajon2H1 && now.minute() == cajon2M1 && now.second() == cajon2S1) || (now.hour() == cajon2H2 && now.minute() == cajon2M2 && now.second() == cajon2S2)){
  digitalWrite(led2,HIGH);
  tone(pito, 550);
  pantalla("DALSY", "4         ");
  Serial.println("el led2 esta encendido");
}
if (digitalRead(cajon2) == 1){
      digitalWrite(led2,LOW); 
      noTone(pito);
      pantallaoff();
      nombre();
    


      }

    //led3 y cajon3
if ((now.hour() == cajon3H1 && now.minute() == cajon3M1 && now.second() == cajon3S1) || (now.hour() == cajon3H2 && now.minute() == cajon3M2 && now.second() == cajon3S2)){
  digitalWrite(led3,HIGH);
  tone(pito, 550);
  pantalla("IBUPROFENO", "4        ");
  Serial.println("el led3 esta encendido");
}
if (digitalRead(cajon3) == 1){
      digitalWrite(led3,LOW); 
      noTone(pito);
     pantallaoff();
     nombre();

      }

   //led4 y cajon4
if ((now.hour() == cajon4H1 && now.minute() == cajon4M1 && now.second() == cajon4S1) || (now.hour() == cajon4H2 && now.minute() == cajon4M2 && now.second() == cajon4S2)){
  digitalWrite(led4,HIGH);
  tone(pito, 550);
  pantalla("NOLOTIL", "4        ");
  Serial.println("el led4 esta encendido");
}
if (digitalRead(cajon4) == 1){
      digitalWrite(led4,LOW); 
      noTone(pito); 
      pantallaoff();
      nombre();

      }

   //led5 y cajon5
if ((now.hour() == cajon5H1 && now.minute() == cajon5M1 && now.second() == cajon5S1) || (now.hour() == cajon5H2 && now.minute() == cajon5M2 && now.second() == cajon5S2)){
  digitalWrite(led5,HIGH);
  tone(pito, 550);
  pantalla("GELOCATIL", "4       ");
  Serial.println("el led5 esta encendido");
}
if (digitalRead(cajon5) == 1){
      digitalWrite(led5,LOW); 
      noTone(pito); 
     pantallaoff();
     nombre();
 
      }
      
Serial.println(digitalRead(cajon1));
Serial.println(digitalRead(cajon2));
Serial.println(digitalRead(cajon3));
Serial.println(digitalRead(cajon4));
Serial.println(digitalRead(cajon5));

delay(100);
}
