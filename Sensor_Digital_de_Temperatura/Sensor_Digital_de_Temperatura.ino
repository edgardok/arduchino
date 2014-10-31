  /*
  Necesito un boton para acceder al modo seleccion de temperatura y con el mismo boton guardar los cambios.
  
  dos botones pra subir y bajar el numero seleccinado
  
  Tomo ese numero y digo cuando la temperatura sea ese numero == hacer habilitar salidas
  
  Leer siempre la variable del sensor
  
  
  */


int numero = 0; 
int estadoBoton1 = 0; 
int estadoBoton2 = 0; 
int salrele=12;
int saltran=11;
int saltriac=10;
int flag=0;
int temp=0;
int accion=0;
int control=0;
int botonedit=0; //boton 3
int cancel=4; //es stop y clear del valor de temperatura de accion
int estadoBoton3 =0;
int estado=0;


void setup() {                 

  pinMode(1, INPUT); 
  pinMode(2, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
  
  Serial.begin(9600);

} 


void loop() {
 
 
cancel=1;

if(digitalRead(4)==LOW){  
cancel=0; 
}  

switch(cancel){
  
  
case 0://reseteamos todo



break;
  
case 1: 
  
  menu()

 
break;
 
 
////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////SECCION SALIDAS//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
  

/*AC VAN TODAS LAS SALIDAS*/



 /*leer temperatura y mostrarla*/
  
  temp=analogRead(A0);

Serial.println(temp);






if(temp == control){

//ejecuto lo que quiero
}




break;


}/*switch*/}/*loop*/






void menu(){
  
  ///////////////////////////////////////////////////////////////////////////////////
//////////////////////////SECCION EDICION//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

  botonedit = digitalRead(3); //leemos el estado del boton de edicion
  
 if (botonedit==LOW){
   
   flag=flag+1;//controlmos cuantas veces fue oprimido el control de edicion y si es la primera vamos a editar la temperatura de accion
 
 while(digitalRead(3)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
 
     
if (flag==2)/*leemos el flag si es 2 significa que fue oprimido el boton de edicion una vez y

 esta es la segunda por lo tanto vamos a guardar el valor del numero de tempetarura de accion*/
 {
 
 flag=0; //reiniciamos el flag
 control=numero;// asignamos a la variable control el numero de temperatura de control

 } 

    

  delay(200); //damos un tiempo de accion
   


 if(flag==1){ 
   
    /*botones de seleccion*/
  estadoBoton1 = digitalRead(1); 
  estadoBoton2 = digitalRead(2); 
  

  if (estadoBoton1 == LOW and numero < 10) { 
    numero = numero + 1; 
  } 

  if (estadoBoton2 == LOW and numero > 0) { 
    numero = numero - 1; 
  }
  /*fin botones de seleccion*/
  
   switch (numero)//elegimos el numero de temperatura de accion

 { 
    case 0: 
        
      break; 
    case 1: 
     
      break; 
    case 2: 
        
      break; 
    case 3: 
      
      break; 
    case 4: 
      
      break; 
    case 5: 
       
      break; 
    case 6: 
       
      break; 
    case 7: 
        
      break; 
    case 8: 
      
      break; 
    case 9: 
      
      break; 
     
  } 
 
  
  }




