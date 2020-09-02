/*
   ################
   #   Lab15125   #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor ultrasonico ping (parallax)

   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746' Inches ; TO_CM = 29_034' Centimeters ]

   El circuito:
     * +V conectado a sensor PING))) en +5V
     * GND conectado a sensor PING))) en GND (ground)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)

   Funcion
   readUltrasonicDistance(int triggerPin, int echoPin): Referencia obtenida de sensor ultrasonico tinkercad.com
*/


/*
Inicio declaracion funcion readUltrasonicDistance
*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);
}
/*
Fin declaracion funcion readUltrasonicDistance
*/


/*
Inicio funcion setup
*/
void setup()
{
  Serial.begin(9600); //Se llama función serial para conectar monitor serial con ejecución del código a 9600 b
  pinMode(8, OUTPUT); //se define pin 8 para LED VERDE como salida
  pinMode(5, OUTPUT); //se define pin 8 para LED AMARILLO como salida
  pinMode(2, OUTPUT); //se define pin 8 para LED ROJO como salida
}
/*
Fin funcion setup
*/


/*
Inicio funcion loop
*/
void loop()
{
  //Se define variale distancia como valor entero con dos decimales
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);

//Condiciones para encendido de leds


  if((distancia <= 336) && (distancia >= 200)) { //si la distancia es menor o igual a 336 cm y mayor o igual a 200 encienda pin 8
    digitalWrite(8, HIGH);
  } 
  else { //si no se cumple la condicion anterior apague pin 8
    digitalWrite(8, LOW); 
  }
  if((distancia < 200) && (distancia >= 100)) { //si la distancia es menor a 200 cm y mayor o igual a 100 encienda pin 7
    digitalWrite(7, HIGH);
  } 
  else { //si no se cumple la condicion anterior apague pin 7
    digitalWrite(7, LOW); 
  }
  if(distancia < 100) { //si la distancia es menor a 100 cm encienda pin 4
    digitalWrite(4, HIGH);
  } 
  else { //si no se cumple la condicion anterior apague pin 4
    digitalWrite(4, LOW); 
  }
  Serial.print("distancia: "); //funcion que arrojará en el monitor de serie la palabra "distancia"
  Serial.println(distancia);   //función que arrojará al ladode la palabra distancia el número de la distancia real del punto

  delay(10); // Delay a little bit to improve simulation performance
}
/*
Inicio funcion loop
*/

/*
 #######################
 #   Fin de programa   #
 #######################
*/
