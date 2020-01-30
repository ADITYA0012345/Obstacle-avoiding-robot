int motorL1=3;  
int motorL2=2;  
int motorR1=5;  
int motorR2=4;              

const int vcc = A0; 
const int trig = A1;
const int echo = A2; 
const int gnd = A3; 

int duration;
int distance;            
void setup() 
{  
    Serial.begin(9600);
   
    pinMode(motorL1,OUTPUT);
    pinMode(motorL2,OUTPUT);
    pinMode(motorR1,OUTPUT);
    pinMode(motorR2,OUTPUT);

    

    pinMode(echo,INPUT);
    pinMode(trig, OUTPUT);
    
    pinMode (vcc,OUTPUT);
    pinMode (gnd,OUTPUT);

    digitalWrite(vcc,HIGH);      
    digitalWrite(gnd,LOW);      
        
    pinMode(echo,INPUT);
    pinMode(trig, OUTPUT);

    
     
}            
void loop() 
{                
       
        digitalWrite(trig, LOW);    
        delayMicroseconds(2);       
        
        digitalWrite(trig, HIGH);   
        delayMicroseconds(10);      
        digitalWrite(trig, LOW);     
        duration = pulseIn(echo, HIGH);                                                 
        distance = duration*0.034/2;
       
          if (distance < 15)  
           { Serial.println("Moving right");
              right();                          
              delay(500);
           } 
           else 
           
           { Serial.println("Moving Forward"); 
              fwd();                              
           }       

}      

void fwd()                                     

{ 
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);

}
void bck()                                      
{ 
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);

}
void left()                                     
{
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);

}

void right()                                    
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);

}

void nomove()                                   
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,LOW);
}
