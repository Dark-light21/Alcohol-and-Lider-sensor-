#define sensor A1 
float x = 1023;
int y;
int sensorValue;
void alcohol();// alcohol module 
void lider();// lider module 

boolean  flag1 = false; // interval variable 
void setup() {
  
  Serial.begin(9600);
}

void loop() {
  // lider();//calling lider module 
 sensorValue = analogRead(A0);
   alcohol();

}


void alcohol(){
  
   y = ((sensorValue/x)*100);
   Serial.print("Alcohol percentage is:");
   Serial.print(" ");
  Serial.print(y);
   Serial.println("%");
   Serial.print("Analog value is : ");
    Serial.println(sensorValue);
    if (y > 70 && flag1 == true)
    {
      Serial.println("You are drunk what are you donig on the road?"); // Beacuse of flag it will only print once 
      flag1 = false;
      }
      if (y < 50 && flag1 == false)
      {
        Serial.println("You are good to go buddy stay safe");
      flag1 = true;
        }
 
  delay(500);        // delay in between reads for stability
}


void lider()//for lider function 
{
  float volts = analogRead(sensor)*0.0048828125;
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  delay(300); // slow down serial port 
  // value from sensor * (5/1024)
 //   Serial.println( volts);                                                                                                   
   Serial.println(distance);
}











  
