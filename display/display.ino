/*
 edgardoDOTkrauseATgmailDOTcom
 
  Necesito un boton para acceder al modo seleccion de temperatura y con el mismo boton guardar los cambios.
  
  dos botones pra subir y bajar el numero seleccinado
  
  Tomo ese numero y digo cuando la temperatura sea ese numero == hacer habilitar salidas
  
  Leer siempre la variable del sensor
  
*/
  
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int numero = 0;           //numero de temperatura de control 
int estadoBoton1 = 0;     //boton para subir la temperatura de control
int estadoBoton2 = 0;     //boton para descender la temperatura de control
int salrele=1;            //pin al rele
int saltran=6;            //pin al transistor
int saltriac=0;           //pin al triac
int flag=0;               //variable de acceso a la edicion
int temp=0;               //temperatura del sensor
int control=0;            //
int botonedit=0;          //boton 3
int cancel=7;             //es stop y clear del valor de temperatura de accion
int estadoBoton3 =0;      //
int estado=0;             //
int up=0;
int down=0;

void setup() {//setup

 lcd.begin(16, 2);//iniciamos el lcd
  
  pinMode(0,OUTPUT);        //salida a triac
  pinMode(1, OUTPUT);       //salida a rele
  pinMode(6, OUTPUT);       //salida a transistor
  pinMode(7, INPUT_PULLUP); //boton RESET
  pinMode(8, INPUT_PULLUP); //boton de seleccion
  pinMode(9, INPUT_PULLUP); //boton de seleccion
  pinMode(10,INPUT_PULLUP); //boton edit/save
  pinMode(13, OUTPUT); 
  
  Serial.begin(9600);//iniciamos el serial
  
}//setup

void loop(){//loop


          leertemp();  
          editmode();
          accion();

}//loop

void leertemp(){//leertemp

   temp=analogRead(A0);//leemos el sensor de temperatura LM35

}//leertemp

void editmode(){//editmode


  
  botonedit = digitalRead(10); //leemos el estado del boton de edicion
     while(digitalRead(10)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion

 /* estadoBoton1 = digitalRead(8); //botones de seleccion
     while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
   
  estadoBoton2 = digitalRead(9); //botones de seleccion
     while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion*/
  
  
 if (botonedit==LOW)                              {//ifbotonedit
     
     flag++;//controlamos cuantas veces fue oprimido el control de edicion y si es la primera vamos a editar la temperatura de accion
     lcd.setCursor(0,0);
     lcd.clear();
     lcd.print("Edicion pulse ");
     lcd.setCursor(0,2);
     lcd.print("UP o DOWN");
     botonedit=HIGH;//mantengo en alto para no entrar al mismo if dos veces
   
                                                    }//ifbotonedit

 
  if (flag==1 && digitalRead(8)==LOW && numero >= -20) {//if50 
    
    while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    numero = numero + 1; 
    lcd.setCursor(0,2);
    lcd.print(numero);
                                                     }//if50
 
 
  if (flag==1 && digitalRead(9)==LOW && numero <= 150){ //if40
   
    while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    numero=numero - 1; 
    lcd.setCursor(0,2);
    lcd.print(numero);
                                                      }//if20 
                                                    
                                                      
if (flag==2 ){ //if40
   
     
    lcd.setCursor(0,0);
    lcd.print("UP or DOWN              ");
    lcd.setCursor(0,2);
    lcd.print("                   ");

                                                      }//if20 
                                                      
                                                      
  if (flag==2 && digitalRead(8)==LOW ){ //if40
   
    while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    up=1; 
    down=0;
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("UP SET");
                                                      }//if40 


  if (flag==2 && digitalRead(9)==LOW){ //if40
   
    while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    down=1;
    up=0;
    lcd.setCursor(0,2);
    lcd.clear();
    lcd.print("DOWN SET");
                                                      }//if40 
 
 
 
     
if (flag==3)
/*leemos el flag si es 2 significa que
**fue oprimido el boton de edicion una vez 
****y esta es la segunda por lo tanto vamos a 
*****guardar el valor del numero de tempetarura de accion*/
                                                      {//if60
   
   lcd.setCursor(0,0);
   lcd.clear();
   lcd.print(flag);
   
   delay(200); //damos un tiempo de accion
   
   flag=0; //reiniciamos el flag
   
   control=numero;// asignamos a la variable control el numero de temperatura de control
   
   
                                                         }//if60

    
}//editmode 

void accion(){//accion
  
 
if(up==1 && temp >= control){//if90

  digitalWrite(saltran,HIGH);
  digitalWrite(salrele,HIGH);
  digitalWrite(saltriac,HIGH);
                    }//if90
                    
if(down==1 && temp >= control){//if90

  digitalWrite(saltran,HIGH);
  digitalWrite(salrele,HIGH);
  digitalWrite(saltriac,HIGH);
                    }//if90

}//accion
