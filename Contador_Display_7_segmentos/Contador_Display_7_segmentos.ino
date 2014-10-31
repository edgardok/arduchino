/*

Contador con Display de 7 segmentos

*/



/*LIBRERIA DE 7 SEGMENTOS
#include "SevSeg.h"
//Create an instance of the object.
SevSeg sevseg;
*/

boton=4;
veces=0;
estado=0;




void setup(){
  
  
  /* LIBRERIA DE 7 SEGMENTOS
 //I am using a common anode display, with the digit pins connected
  //from 2-5 and the segment pins connected from 6-13
  sevseg.Begin(1,2,3,4,5,6,7,8,9,10,11,12,13);
  //Set the desired brightness (0 to 100);
  sevseg.Brightness(90);
  */
  
  
  
pinMode(boton,Input);



}

void loop(){

estado=digitalRead(boton);

if(estado==HIGH){veces++;}

while(digitalRead(boton)==HIGH){}

/*
ESTO ES PARTE DE LA LIBRERIA

 //Produce an output on the display
  sevseg.PrintOutput();
  
  //Update the number to be displayed, with a decimal
    //place in the correct position.
    sevseg.NewNum(CentSec,(byte) 2);
*/



switch(veces){

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

case 10:

break;

}


}
