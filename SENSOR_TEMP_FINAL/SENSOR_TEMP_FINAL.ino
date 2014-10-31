/*
 edgardoDOTkrauseATgmailDOTcom
 
 Siempre muestro la lectura del sensor
 
 Con el boton aplicado en el pin 10 entras al modo de Edicion
 
 Se edita la temperatura de accion
 
 Se edita si la accion sera sobre o debajo de la temperatura
 
 Se ejecuta la accion al llegar a la temperatura deseada
  
*/
  
#include <LiquidCrystal.h>



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int numero = 0;           //numero de temperatura de control 
int estadoBoton1 = 0;     //boton para subir la temperatura de control
int estadoBoton2 = 0;     //boton para descender la temperatura de control
int salrele=13;            //pin al rele
int saltran=1;            //pin al transistor
int saltriac=6;           //pin al triac
int flag=0;               //variable de acceso a la edicion
float temp=0;             //temperatura del sensor
int control=0;            //variable que compara a la temperatura para accionar
int botonedit=HIGH;       //variable que da acceso al modo de edicion
int cancel=7;             //es stop y clear del valor de temperatura de accion
int up=0;                 //variable para accionar sobre la temperatura elejida
int down=0;               //variable para accionar debajo de la temperatura elejida
int leer=0;               //habilita o deshabilita las tareas
int primer_pasada=0;      //inicializa las salidas en low solo en la primer pasada
 

void setup() {//setup

 lcd.begin(16, 2);//iniciamos el lcd
  
  //pinMode(0,OUTPUT);        //salida a triac
 // pinMode(1, OUTPUT);       //salida a rele
  pinMode(6, OUTPUT);       //salida a transistor
  pinMode(7, INPUT_PULLUP); //boton RESET
  pinMode(8, INPUT_PULLUP); //boton de seleccion
  pinMode(9, INPUT_PULLUP); //boton de seleccion
  pinMode(10,INPUT_PULLUP); //boton edit/save
  pinMode(13, OUTPUT);      //salida
  analogReference(INTERNAL);
  
  Serial.begin(9600);//iniciamos el serial
  
}//setup


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%LOOP%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void loop(){//loop
    //goto inicio para el reset?? un incio aca para que muestre la temp pero no pase de ahi
          
                    
         
         
        iniciarsalidas(); 
        reset();  
        
        
        if(leer==1){//IFestadoreset

lcd.clear();
     leertemp(); 
     lcd.setCursor(0,2);
     lcd.print("RESET");
     lcd.print(" ACTIVO");  


}//IFestadoreset


              
         leertemp();          
         editmode();
         accion();
        

}//loop


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%FIN LOOP%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


void iniciarsalidas(){//iniciar

         
        if(primer_pasada==0)  {//if      
        digitalWrite(salrele,LOW);
        primer_pasada=1;
        Serial.println(salrele);
        
        }//if
         

}//iniciar


////////////////////////////////////FUNCION RESET/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reset(){//reset

  if(leer==0 && digitalRead(7)==LOW){//5
  
  while(digitalRead(7)==LOW){}//frenamos toda accion mientras es oprimido el boton de cancelar
  leer=1;  
     
  
  }//5
  
  if(leer==1 && digitalRead(7)==LOW){//7
    while(digitalRead(7)==LOW){}//frenamos toda accion mientras es oprimido el boton de cancelar
    leer=0;
  
  }//7

}//reset

//////////////////////FIN FUNCION CANCELAR/RESET///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////FUNCION LEER TEMPERATURA////////////////////////////////////////////////////////////////////////////////////////////////////////////
void leertemp(){//leertemp


if(flag==0 && botonedit==HIGH){//if10
     
     
     
     delay(1000);
      temp=(1.1*analogRead(A0)*100.00/1024.00)-5;

   
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("TEMP = ");
     lcd.print(temp);
     lcd.print(" C");  
     
}//if10
}//leertemp

/////////////////////////FIN FUNCION LEER TEMPERATURA///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////FUNCION EDITAR////////////////////////////////////////////////////////////////////////////////////////////

void editmode(){//editmode


  
  botonedit = digitalRead(10); //leemos el estado del boton de edicion
     while(digitalRead(10)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
     
     

  /*estadoBoton1 = digitalRead(8); //botones de seleccion
     while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
   
  estadoBoton2 = digitalRead(9); //botones de seleccion
     while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion*/
  
  
 if (botonedit==LOW && leer==0)                              {//ifbotonedit
     
     flag=flag + 1;//controlamos cuantas veces fue oprimido el control de edicion y si es la primera vamos a editar la temperatura de accion
     lcd.setCursor(0,0);
     lcd.clear();
     lcd.print("Edicion pulse ");
     lcd.setCursor(0,2);
     lcd.print("UP o DOWN");
     botonedit=HIGH;//mantengo en alto para no entrar al mismo if dos veces
   
                                                    }//ifbotonedit

 
  if (flag==1 && digitalRead(8)==LOW && numero >= -20 ) {//if20 
    
    while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    numero = numero + 1; 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Modo Edicion");
    lcd.setCursor(0,2);
    lcd.print("Temp. Sel. ");
    lcd.print(numero);
    
                                                     }//if20
 
 
  if (flag==1 && digitalRead(9)==LOW && numero <= 150){ //if30
   
    while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    numero=numero - 1; 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Modo Edicion");
    lcd.setCursor(0,2);
    lcd.print("Temp. Sel. ");
    lcd.print(numero);
                                                      }//if30 
                                                    
                                                      
                                                
                                                      
  if (flag==2 && digitalRead(8)==LOW){ //if40
   
    while(digitalRead(8)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    up=1; 
    down=0;
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("UP SET");
                                                      }//if40 
                                                      
   if (flag==2 && up==1 ){ //if50
   
    down=0;
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("UP SET");
                                                      }//if50 
                                                      
                                                      

//leemos y seteamos el down
  if (flag==2 && digitalRead(9)==LOW){ //if60
   
    while(digitalRead(9)==LOW){} //frenamos toda accion mientras es oprimido el boton de edicion
    down=1;
    up=0;
    lcd.setCursor(0,2);
    
    lcd.print("DOWN SET");
                                                      }//if60 
                                                      
  //printeamos el down
   if (flag==2 && down==1){ //if70
   
   
    up=0;
    
    lcd.setCursor(0,2);
    lcd.print("DOWN SET");
                                                      }//if70 
 
 
 
     
if (flag==3)
/*leemos el flag si es 2 significa que
**fue oprimido el boton de edicion una vez 
****y esta es la segunda por lo tanto vamos a 
*****guardar el valor del numero de tempetarura de accion*/
                                                      {//if80
   
   lcd.setCursor(0,0);
   lcd.clear();
   lcd.print("TEMP. ACC. = ");
   lcd.print(numero);
   
   delay(2000); //damos un tiempo de accion
   
   flag=0; //reiniciamos el flag
   
   control=numero;// asignamos a la variable control el numero de temperatura de control
   
   
                                                         }//if80

    
}//editmode 
/////////////////////////////FIN FUNCION EDITAR//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////FUNCION ACCION/////////////////////////////////////////////////////////////////////////////////////////
void accion(){//accion
  
 
if(up==1 && temp >= control && leer==0){//if90

 digitalWrite(saltran,HIGH);
 digitalWrite(salrele,HIGH);
 digitalWrite(saltriac,HIGH);
                    }//if90
                    
if(down==1 && temp <= control && leer==0){//if100

 digitalWrite(saltran,HIGH);
 digitalWrite(salrele,HIGH);
 digitalWrite(saltriac,HIGH);
                    }//if100

}//accion
///////////////////////FIN FUNCION ACCION//////////////////////////////////////////////////////////////////////////////////////////////////
