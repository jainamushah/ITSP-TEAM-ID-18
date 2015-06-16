int counter=0;
unsigned long int timearr[20];
unsigned long int error=0;
int ctr=0;


void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13,OUTPUT);
  
}


void loop()
{
  digitalWrite(12,HIGH);

 
  if(Serial.available()>0)
  {
    const char set_reset=Serial.read();
    if(set_reset=='R')
    {  error=millis();
       Serial.println("enter in R loop");
      while(1)
      {  
        const char stop_run=Serial.read();
        if(stop_run=='r')
        {
         Serial.println("enter in r loop");
          digitalWrite(11, HIGH);
         digitalWrite(10, HIGH);
         digitalWrite(8, HIGH);
         digitalWrite(9, LOW); 
     
         Serial.println("exit in r loop");
      }
        else if(stop_run=='s')
        {
          /*int starttime1=millis();
          int endtime1=starttime1;
          while((endtime1-starttime1)<=0)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            endtime1=millis(); 
          }*/

          int starttime2=millis();
          int endtime2=starttime2;
          while((endtime2-starttime2)<=1000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
            endtime2=millis();
          }
          
          int starttime1=millis();
          int endtime1=starttime1;
          while((endtime1-starttime1)<=300)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8 , LOW);
            endtime1=millis(); 
          }
          
          int starttime3=millis();
          int endtime3=starttime3;
          while((endtime3-starttime3)<=2000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
            endtime3=millis();
          }
       
         // timearr[counter]=millis()-error;
        }
             else  if(stop_run=='m')
       {
         int starttime4=millis();
          int endtime4=starttime4;
          while((endtime4-starttime4)<=1000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(8, HIGH);
            endtime4=millis();
          }
          
         
                
      }
           else if(stop_run=='x')
           {digitalWrite(13,HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
           }
       /*    else if(stop_run=='w')
           { int starttime4=millis();
          int endtime4=starttime4;
          while((endtime4-starttime4)<=1000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
            endtime4=millis();
          }}
          else if(stop_run=='g')
          {
              digitalWrite(11, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
           }
           
           else if(stop_run=='z')
           
        {   int starttime4=millis();
          int endtime4=starttime4;
          while((endtime4-starttime4)<=1000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
            endtime4=millis();
          }
        } */
           
           
           
           
           
           
           
           
           
           
           
           
  }}}}
      
      /*const char stop_run=Serial.read();
      
      if(stop_run=='r')
        {
         digitalWrite(11, HIGH);
         digitalWrite(10, LOW);
         digitalWrite(9, HIGH);
         digitalWrite(8, HIGH); 
        }
      else if(stop_run=='s')
        {
          int starttime1=millis();
          int endtime1=starttime1;
          while((endtime1-starttime1)<=500)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
           endtime1=millis(); 
          }
          int starttime2=millis();
          int endtime2=starttime2;
          while((endtime2-starttime2)<=1000)
          {
            digitalWrite(11, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(8, HIGH);
          }*/
          
       
      /* counter=10;
       
       while(counter<20)
       {  
         const char stop_run=Serial.read();
         if(stop_run=='r')
         {
          digitalWrite(11, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(8, LOW); 
         }
         else if(stop_run=='s')
         {
           digitalWrite(11, HIGH);
           digitalWrite(10, HIGH);
           digitalWrite(9, HIGH);
           digitalWrite(8, HIGH);
           timearr[counter]=millis()-error;
          counter++;
         delay(1000); 
         }
       }
       
       const char stop_run=Serial.read();
      
      if(stop_run=='r')
        {
         digitalWrite(11, LOW);
         digitalWrite(10, HIGH);
         digitalWrite(9, HIGH);
         digitalWrite(8, HIGH); 
        }
      else if(stop_run=='s')
        {
          digitalWrite(11, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(8, HIGH);
        }
    }
    else if(set_reset=='S')
    {*/
      
       
      
      
