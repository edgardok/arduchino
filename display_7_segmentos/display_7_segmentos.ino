CÓDIGO:

int a = 0; 
int D1_segmento_a=0;  
int D1_segmento_b=1;  

void setup()
{
  
pinMode(D1_segmento_a,OUTPUT);
pinMode(D1_segmento_b,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);

}

void loop()
{ 

if (a==0)
{  
//numero 0
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
}

//numero 0
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,HIGH);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,LOW);
delay(500); 

//numero 1
digitalWrite(6,LOW);
digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,HIGH);
digitalWrite(D1_segmento_a,HIGH);
delay(500);

//numero 2
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,HIGH);
digitalWrite(3,LOW);
digitalWrite(2,HIGH);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,LOW);
delay(500);

//numero 3
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,HIGH);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,HIGH);
delay(500);

//numero 4
digitalWrite(6,LOW);
digitalWrite(5,HIGH);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,HIGH);
digitalWrite(D1_segmento_a,HIGH);
delay(500);

//numero 5
digitalWrite(6,HIGH);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,HIGH);
delay(500);

//numero 6
digitalWrite(6,HIGH);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,LOW);
delay(500);

//numero 7
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,HIGH);
digitalWrite(D1_segmento_a,HIGH);
delay(500);

//numero 8
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,LOW);
digitalWrite(D1_segmento_a,LOW);
delay(500);

//numero 9
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(D1_segmento_b,HIGH);
digitalWrite(D1_segmento_a,HIGH);
delay(500);



a=a+1;

if (a==1)
{

 //numero 1
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
digitalWrite(9,LOW);
digitalWrite(8,HIGH);
digitalWrite(7,HIGH); 
  
}

if (a==2)
{

//numero 2
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
digitalWrite(9,HIGH);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
  
}

if (a==3)
{

//numero 3
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,HIGH);
  
}

if (a==4)
{

//numero 4
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);
  
}

if (a==5)
{
  
//numero 5
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,HIGH);
  
}

if (a==6)
{

//numero 6
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
  
}

if (a==7)
{

//numero 7
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
digitalWrite(9,LOW);
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);
  
}

if (a==8)
{

//numero 8
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
  
}

if (a==9)
{

 //numero 9
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(9,LOW);
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);

a=0;
  
}


}
