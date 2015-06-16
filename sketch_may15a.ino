  
void setup() 
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() 
{
  digitalWrite(12, HIGH);
  
  if(Serial.available()>0)
  {
    const char c = Serial.read();
    if (c=='w')
    {
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      
    }
    else if(c=='s')
    {
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      //delay(5000);
    }
     else if(c=='a')
    {
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      
    }
 else if(c=='d')
    {
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      
    }
  else
 
  {
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
    
    
  } 
}}
