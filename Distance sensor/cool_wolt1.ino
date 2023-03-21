// C++ code
//
int distanceThreshold =0;
int cm = 0;
int inches =0;
long readUltrasonicDistance(int triggerPin,int echoPin)
{
    pinMode(triggerPin,OUTPUT);
  digitalWrite(triggerPin,LOW);
  delay(2000);
  digitalWrite(triggerPin,HIGH);
  delay(1000);
  digitalWrite(triggerPin,LOW);
  pinMode (echoPin,LOW);
  return pulseIn(echoPin,HIGH);        

  
} 

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
    
  
}

void loop()
{
  distanceThreshold=400;
    cm = 0.01723*readUltrasonicDistance(6,5);
    inches=(cm/2.54);
  Serial.print(cm);
  Serial.print("cm,");
  Serial.print(inches);
  Serial.println("in");
  
  digitalWrite(2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(3, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(3, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(4, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  

if(cm > distanceThreshold){
  digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW); 
}

if(cm <= distanceThreshold && cm >distanceThreshold-150){
  digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);    
}
if(cm<=distanceThreshold -150 && cm >distanceThreshold-300){
  digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,LOW);    
}
if(cm<=distanceThreshold -300 && cm >distanceThreshold-400){
  digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);    
}
delay(100);


}





