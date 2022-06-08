
#define BLYNK_PRINT Serial

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLR_3nhk4D"
#define BLYNK_DEVICE_NAME "Parking System"
#define BLYNK_AUTH_TOKEN "x7VNekOtNJLCm6IgxunipqwFn-O3wB9-";
/*#define BLYNK_GREEN  "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"*/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Denis";
char pass[] = "dennoh123";

/*WidgetLED pins1(V10);
WidgetLED pins2(V11);
WidgetLED pins3(V12);
WidgetLED pins4(V13);
WidgetLED pins5(V14);
WidgetLED pins6(V15);*/

BlynkTimer timer;


String myString; //complete message from arduino, which consistors of snesors data
char rdata; //received character


int firstVal, secondVal, thirdVal; //sensors
int led1, led2, led3, led4, led5, led6;

//This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

BLYNK_CONNECTED()
  {
    Blynk.virtualWrite(V8, " Welcome to Murang'a County");
  }


void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis()/1000);
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

     timer.setInterval(1000L,sensorValue1);
     timer.setInterval(1000L,sensorValue2); 
     timer.setInterval(1000L,sensorValue3);
     timer.setInterval(1000L,sensorvalue4);
     timer.setInterval(1000L,sensorvalue5);
     timer.setInterval(1000L,sensorvalue6);
}

void loop()
{
  if (Serial.available() == 0)
  {
    Blynk.run();
    timer.run(); //Initiates BlynkTimer
   }
   if (Serial.available() > 0)
   {
    rdata = Serial.read();
    myString = myString+ rdata;

    //Serial.print (rdata);
    if ( rdata == '\n')
    {
      Serial.println(myString);
      //Serial.println("Denis");
      //new code
String l = getValue(myString, ',', 0); 
String m = getValue(myString, ',', 1); 
String n = getValue(myString, ',', 2); 
String o = getValue(myString, ',', 3); 
String p = getValue(myString, ',', 4); 
String q = getValue(myString, ',', 5); 

//these leds represents the leds used in Blynk application
led1 = l.toInt();
led2 = m.toInt();
led3 = n.toInt();
led4 = o.toInt();
led5 = p.toInt();
led6 = q.toInt();
      myString = "";
      //end code here
      }
    } 
}

void sensorValue1()
{
  int sdata = led1;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V10, sdata);

  }
void sensorValue2()
{
  int sdata = led2;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V11, sdata);
  }
void sensorValue3()
{
  int sdata = led3;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V12, sdata);
  
  }
void sensorvalue4()
{
  int sdata = led4;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V13, sdata); 
  }
void sensorvalue5()
{
  int sdata = led5;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V14, sdata);
  }
void sensorvalue6()
{
  int sdata = led6;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V15, sdata);
 
 }
 
//Splits the string message using comma as the delimitor. 
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1 };
  int maxIndex = data.length() - 1;


  for (int i = 0; i <= maxIndex && found <= index; i++){
    if (data.charAt(i) == separator || i == maxIndex){
      found++;
      strIndex[0] = strIndex[1] = 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

















  

























  
