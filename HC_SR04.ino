#include<Ultrasonido.h> //Se incluye la librería

boolean started=false; //variable que sirve de interruptor para el envio de datos

int frecuencia=1000; //Frecuencia para el envio de datos
int input;
int dist;
int unidad; int decena; //Estas variables permitirán recibir la distancia
int freq;
double distancia;
void setup(){
Serial.begin(9600);
}

void loop(){
if (Serial.available()>0){
input=Serial.read(); //Se lee b o c, para encender o apagar el envio de datos
delay(2); //Un retraso de 2 milisegundos
freq=Serial.read(); //Se lee la frecuencia
delay(2);
decena=Serial.read()-48; //Se lee las decenas de la distancia
delay(2);
unidad=Serial.read()-48; //Se leen las unidades
dist=(10*decena)+unidad; //Se multiplica las decenas por 10 y se le suma las unidades

//Se inicia o se detiene el envio de datos a Java
if (input=='b'){
started=true;
}
if (input=='c'){
started=false;
}

//Se establece la frecuencia del envio de datos
switch (freq){
case '1':
frecuencia=1000;
break;
case '2':
frecuencia=2000;
break;
case '3':
frecuencia=3000;
break;
case '4':
frecuencia=4000;
break;
case '5':
frecuencia=5000;
break;
case '6':
frecuencia=6000;
break;
case '7':
frecuencia=7000;
break;
case '8':
frecuencia=8000;
break;
case '9':
frecuencia=9000;
break;
case 'a':
frecuencia=10000;
break;

}
}
if (started==true){ //Condicion que empieza o apaga el envio de datos
Ultrasonido ultrasonido(9,8,100); //Se declara la variable del sensor
distancia=ultrasonido.Distancia();  //Se lee la distancia

Serial.print(distancia); //Se imprime la distancia

Serial.print(','); //Separador entre un dato y otro
}
delay(frecuencia); //Intervalo de envio de datos
}
