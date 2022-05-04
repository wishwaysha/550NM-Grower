#include <dht.h> 
dht DHT;
int rain_cover=1,pump=0;
void setup(){
  Serial.begin(115200);
 // pinMode(2,INPUT);//soilMoisture sensor
  pinMode(6,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(9,OUTPUT);
  //pinMode(3,INPUT);//Rainwater sensor
  pinMode(14,INPUT);//DHT
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
 
  }
void loop()
{
  float rain_check = analogRead(A3);
  Serial.print("rain sensor = ");
  Serial.print(rain_check); 
  float moisture_check = analogRead(A2);
  Serial.print("  soil moisture = ");
  Serial.print(moisture_check);
  int readData = DHT.read11(14);
  float t = DHT.temperature;  // Read temperature
  float h = DHT.humidity;   // Read humidity
  Serial.print("  Temperature = ");
  Serial.print(t); 
  Serial.print("°C | ");
  Serial.print((t*9.0)/5.0+32.0); // Convert celsius to fahrenheit
  Serial.print("°F ");
  Serial.print(" Humidity = ");
  Serial.println(h);
  if ( moisture_check <600 && rain_check > 200)
  { //open roof 
    Serial.println("Plants need water!! it is raining, hence OPENNING ROOF! pump off");
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW); //openning roof 
    rain_cover=1;
    digitalWrite(9,HIGH);
    delay(6000);
    digitalWrite(2,LOW); //stopping motor 
    digitalWrite(4,LOW);
    digitalWrite(7,LOW); // pump off 
    digitalWrite(3,LOW);
    pump=0;
    digitalWrite(8,LOW);
  }
  else if ( moisture_check <600 && rain_check < 200)
  { //turn on pump
    Serial.println("Plants need water!! Turning the pump on");
    digitalWrite(7,HIGH);
    digitalWrite(3,LOW); //pump on 
    pump=1;
    digitalWrite(8,HIGH);
    if (rain_cover ==1)
        {//closes roof 
           Serial.println("Closing Rain Cover ");  
          digitalWrite(2,LOW);
          digitalWrite(4,HIGH);
          rain_cover=0;
          digitalWrite(9,LOW);
          delay(8000);
          digitalWrite(2,LOW);
          digitalWrite(4,LOW);
        }
    delay(5000);
    if (  moisture_check <600)
    { Serial.println(" water in tank empty");
    }
  }
  else if (  moisture_check>200 && pump==1)
  {//turn off the pump 
    Serial.println(" WATER PUMPED!! moisture level reached. Turning OFF the pump.");
    digitalWrite(7,LOW);
    digitalWrite(3,LOW);
    pump=0;
    digitalWrite(8,LOW);
  }
 else if (  moisture_check >200 && rain_cover==1 && rain_check > 200  )
  {//close the roof  
    Serial.println(" Naturally irrigated!! moisture level reached. Shutting the roof.");
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    rain_cover=0;
    digitalWrite(9,LOW);
    delay(10000);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
  }
  delay(1000);
  }
