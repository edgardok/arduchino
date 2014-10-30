int entrada=4;
int led1=9;
int led2=11;
int veces=0;
int x=0;

void setup()
{
pinMode(entrada,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);

}

void loop(){


 
x= digitalRead(entrada);


if(x==HIGH){
  
  delay(150);
  veces=veces+1;
}



switch(veces){

case 1:

Serial.println("caso 1");
digitalWrite(led1,HIGH);
x=LOW;
   
break;


case 2:

Serial.println("caso 2");
digitalWrite(led2,HIGH);
digitalWrite(led1,LOW);
 x=LOW;
break;


case 3:


      
       Serial.println("caso 3");
      digitalWrite(led1,HIGH);
      delay(200);
      digitalWrite(led1,LOW);
      delay(200);
      digitalWrite(led2,HIGH);
        delay(200);
      digitalWrite(led2,LOW);
        delay(200);
   x=LOW;


break;

case 4:
       Serial.println("caso 4");

      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      veces=0;
      x=LOW;


break;


  }

  
  

}
