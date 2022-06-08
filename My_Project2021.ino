#include <SoftwareSerial.h>

SoftwareSerial nodemcu(2,3); //Connect NodeMcu to port 2 and 3 of the Arduino Uno

//  parking slot1 infrared sensor connected with pin number 4, 5, 6 of arduino

int parking1_slot1_ir_s = 4;
int parking1_slot2_ir_s = 5;
int parking1_slot3_ir_s = 6;

int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;
int parking2_slot3_ir_s = 9;

String sensor1;
String sensor2;
String sensor3;
String sensor4;
String sensor5;
String sensor6;


// Complete Data Consisting of Sensor Values 
String cdata="";

void setup() 
{
  Serial.begin(9600);
  nodemcu.begin(9600);

  pinMode(parking1_slot1_ir_s, INPUT);
  pinMode(parking1_slot2_ir_s, INPUT);
  pinMode(parking1_slot3_ir_s, INPUT);
   
  pinMode(parking2_slot1_ir_s, INPUT); 
  pinMode(parking2_slot2_ir_s, INPUT); 
  pinMode(parking2_slot3_ir_s, INPUT); 
}

void loop()
{
  p1slot1();
  p1slot2();
  p1slot3();
  
  p2slot1();
  p2slot2();
  p2slot3();


      //Comma acts as a delimeter
      cdata = cdata + sensor1 + "," + sensor2 + "," + sensor3 + ","+ sensor4 + "," + sensor5 + "," + sensor6 + ",";
      Serial.println(cdata);
      nodemcu.println(cdata);
      delay(1000); // 100 milliseconds
      cdata="";

   digitalWrite(parking1_slot1_ir_s, HIGH);
   digitalWrite(parking1_slot2_ir_s, HIGH);
   digitalWrite(parking1_slot3_ir_s, HIGH);
   
   digitalWrite(parking2_slot1_ir_s, HIGH);
   digitalWrite(parking2_slot2_ir_s, HIGH);
   digitalWrite(parking2_slot3_ir_s, HIGH);
}


//Parking1 Slot1
void p1slot1()
{
  if(digitalRead(parking1_slot1_ir_s) == LOW)
  {
    sensor1 = "255";
    delay(200);
  }

  if(digitalRead(parking1_slot1_ir_s) == HIGH)
  {
    sensor1 = "0";
    delay(200);
  }
}

// Parking1 Slot 2
void p1slot2()
{
  if(digitalRead(parking1_slot2_ir_s) == LOW)
  {
    sensor2 = "255";
    delay(200);
  }

  if(digitalRead(parking1_slot2_ir_s) == HIGH)
  {
    sensor2 = "0";
    delay(200);
  }
}


//Parking1 Slot 3
void p1slot3()
{
  if(digitalRead(parking1_slot3_ir_s) == LOW)
  {
    sensor3 = "255";
    delay(200); 
    }

  if(digitalRead(parking1_slot3_ir_s) == HIGH)
  {
    sensor3 = "0";
    delay(200);
  }
}
  
  //Parking2 Slot 1
void p2slot1()
{
  if(digitalRead(parking2_slot1_ir_s) == LOW)
  {
    sensor4 = "255";
    delay(200);
  }

  if(digitalRead(parking2_slot1_ir_s) == HIGH)
  {
    sensor4 = "0";
    delay(200);
  }
}

// Parking2 Slot 2
void p2slot2()
{
  if(digitalRead(parking2_slot2_ir_s) == LOW)
  {
    sensor5 = "255";
    delay(200);
  }

  if(digitalRead(parking2_slot2_ir_s) == HIGH)
  {
    sensor5 = "0";
    delay(200);
  }
}


//Parking2 Slot 3
void p2slot3()
{
  if(digitalRead(parking2_slot3_ir_s) == LOW)
  {
    sensor6 = "255";
    delay(200); 
    }

  if(digitalRead(parking2_slot3_ir_s) == HIGH)
  {
    sensor6 = "0";
    delay(200);
  }
}
