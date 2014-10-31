int numero = 0; 
int estadoBoton1 = 0; 
int estadoBoton2 = 0; 

void setup() {                 

  pinMode(2, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);   

} 


void loop() { 
   
  estadoBoton1 = digitalRead(2); 
  estadoBoton2 = digitalRead(3); 
  

  if (estadoBoton1 == LOW and numero < 10) { 
    numero = numero + 1; 
  } 

  if (estadoBoton2 == LOW and numero > 0) { 
    numero = numero - 1; 
  } 
  
  
  switch (numero) { 
    case 0: 
      limpiar(); 
      cero();    
      break; 
    case 1: 
      limpiar(); 
      uno();  
      break; 
    case 2: 
      limpiar(); 
      dos();  
      break; 
    case 3: 
      limpiar(); 
      tres();  
      break; 
    case 4: 
      limpiar(); 
      cuatro();  
      break; 
    case 5: 
      limpiar(); 
      cinco();  
      break; 
    case 6: 
      limpiar(); 
      seis();  
      break; 
    case 7: 
      limpiar(); 
      siete();  
      break; 
    case 8: 
      limpiar(); 
      ocho();  
      break; 
    case 9: 
      limpiar(); 
      nueve(); 
      break; 
     
  } 

  delay(200); 
   


} 

void cero(){ 
  digitalWrite(10,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
} 

void uno(){ 
  digitalWrite(8,HIGH); 
  digitalWrite(5,HIGH); 
} 
void dos(){ 
  digitalWrite(9,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH); 
  digitalWrite(11,HIGH); 
} 
void tres(){ 
  digitalWrite(6,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
} 
void cuatro(){ 
  digitalWrite(8,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(11,HIGH); 
} 
void cinco(){ 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
} 
void seis(){ 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(11,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH); 

} 
void siete(){ 
  digitalWrite(8,HIGH); 
  digitalWrite(5,HIGH); 
  digitalWrite(9,HIGH); 

} 
void ocho(){ 

  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  digitalWrite(7,HIGH); 
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  digitalWrite(11,HIGH); 
} 
void nueve(){ 

digitalWrite(5,HIGH); 
digitalWrite(8,HIGH); 
digitalWrite(9,HIGH); 
digitalWrite(10,HIGH); 
digitalWrite(11,HIGH); 
} 

void limpiar(){ 
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW); 
  digitalWrite(6,LOW); 
  digitalWrite(7,LOW); 
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW); 
  digitalWrite(11,LOW); 
} 
