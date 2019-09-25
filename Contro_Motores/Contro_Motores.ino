const int enPin = 5; // PWM se conecta al pin 1 del puente-H
 
const int in1Pin = 7; // Entrada 2 del puente-H
 
const int in2Pin = 4; // Entrada 7 del puente-H

const int enPin_1 = 10; //PWN se conecta al pin 11 del puente-H
const int in3Pin = 8;  //Entrada 15 del puente-H
const int in4Pin = 9; //Entrada 10 del puente -H

const int in5Pin = 11; //Entrada del Led
int in = 0;
byte pinOut = 12;
 
void setup() {
 
Serial.begin(9600); //Iniciamos la comunicacion serial
 
pinMode(in1Pin, OUTPUT); 

pinMode(in2Pin, OUTPUT);

pinMode(in3Pin, OUTPUT);
pinMode(in4Pin, OUTPUT);

pinMode(in5Pin, OUTPUT);


pinMode(pinOut, OUTPUT);
//pinMode(Pin_TIP_2, OUTPUT);
 
Serial.println("Para seleccionar la velocidad del motor (0-9). Para seleccionar la direccion introduce + o -"); //Imprime en la consola puerto serie
 
}
 
 
 
void loop() {
 
 
 
  if ( Serial.available()) { //Comprobamos que el puerto serial esta disponible para la comunicacion
 
    char ch = Serial.read(); //Leemos las variables que introducimos desde el teclado por el monitor serial
 
    if(ch >= '0' && ch <= '9') {
 
      int speed = map(ch, '0', '9', 0, 255); // Adaptamos el numero a una escala de 0 a 255
 
      analogWrite(enPin, speed);
      analogWrite(enPin_1, speed);
 
      Serial.println("El valor de velocidad intruducido es:");
 
      Serial.println(speed); //Escribe el valor analogico PWM enPin
 
    }
 
    else if (ch == '+') {
 
      Serial.println("Girando en sentido horario...");
 
      digitalWrite(in1Pin,LOW);
 
      digitalWrite(in2Pin,HIGH);


       digitalWrite(in3Pin,LOW);
 
      digitalWrite(in4Pin,HIGH);

      
       digitalWrite(in5Pin,LOW);
 
      digitalWrite(in5Pin,HIGH);

      analogWrite(in5Pin,LOW);
 

//Tip
      analogWrite(pinOut,in);
    

   
    }
 
    else if (ch == '-') { 
 
      Serial.println("Girando en sentido anti-horario...");
 
      digitalWrite(in1Pin,HIGH);
 
      digitalWrite(in2Pin,LOW);

       digitalWrite(in3Pin,HIGH);
 
      digitalWrite(in4Pin,LOW);

      digitalWrite(in5Pin,HIGH);
 
      digitalWrite(in5Pin,LOW);

      analogWrite(pinOut,in);

 
    }
 
    else {
 
      Serial.print("Caracter no reconocido. Error.");
 
      Serial.println(ch);
 
    }
 
  }
 
}
