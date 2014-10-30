int entrada=4;
int led1=9;
int led2=11;
int veces=0;
int valor=0;
int pulsador=0;

void setup()
{
pinMode(entrada,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);

}

void loop(){
  

  pulsador= digitalRead(entrada);
 
  
  if(pulsador==HIGH && valor==0){
  valor=1;
  digitalWrite(led1,HIGH);
  
  delay(300);
   pulsador=LOW;
  }
  
 
   
    if(pulsador==HIGH && valor==1){
        valor=2;
        digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      
       delay(300);
        pulsador=LOW;
       
       
  
  }
  
  
    if(pulsador==HIGH && valor==2){

       
     inicio:
    
      digitalWrite(led1,HIGH);
      
     
     
      digitalWrite(led1,LOW);
      
      
      
      digitalWrite(led2,HIGH);
     
       
      digitalWrite(led2,LOW);
     
       
        pulsador= digitalRead(entrada);
         if(pulsador==HIGH){
   valor=0;
   pulsador=LOW;
    delay(300);
  goto salida;
  }
  
  goto inicio;
  salida:
  
   valor=3;
   pulsador=LOW;
    delay(300);
  
  }
  
 
    
   
    
   
 
  
  
  
  
  
  
  
  
  
}
