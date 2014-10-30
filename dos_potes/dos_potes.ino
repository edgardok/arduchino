int led1 = 9;
int led2 = 11;
int boton1 = 2;
int boton2 = 4;
void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
}
void loop(){
  
  int valor1;
  int valor2;
  valor1 = analogRead(A0);
  valor2 = analogRead(A1);
  if(valor1<=valor2){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  if(valor1>=valor2){
  
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  
  }
    
  
