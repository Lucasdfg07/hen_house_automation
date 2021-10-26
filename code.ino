// Código exemplo para teste de Micro Servo Motor SG90 
// Movimento do servo através de comandos especificados 
 
#include "Servo.h" // Inclui a Biblioteca Servo.h 
 
Servo meuservo; // Cria o objeto servo para programação 

int i = 0; // Ajusta o ângulo inicial do Servo
int countLuz = 0;
int countServo = 0;
const int ledPin = 8; //led no pino 2
  
unsigned long myTime;

void setup() {
  meuservo.attach(9); // Declara o pino do servo
  meuservo.write(30);
  
  pinMode(ledPin, OUTPUT); //Pino do led será saída
  
  Serial.begin(9600);
}
 
void loop() { 
  myTime = millis();
  countLuz = countLuz + 1;
  countServo = countServo + 1;

  // Desliga/Liga lâmpada de 11 em 11 horas
  // Ao injetar o código, ele liga a lâmpada e depois de 11 horas ligado, ele desliga.
  // ligar 18 horas para apagar 5 da manhã da outro dia.
     
  if(countLuz >= 0 && countLuz < 39600) {
    digitalWrite(ledPin, HIGH); // Desliga lampada
  }

  if(countLuz >= 39600) {
    digitalWrite(ledPin, LOW); // Liga Lampada
  }

  if(countLuz >= 79200) {
    countLuz = 0;
  }

  
  // Código do alimentador de galinhas. 
  if(countServo == 10) {
    meuservo.write(100); // Comando para mover para angulo específico
    delay(1);
  }

  if(countServo >= 20) {
    meuservo.write(30); // Comando para mover para angulo específico
    delay(1);
    countServo = 0;
  }

  Serial.println(countServo);

  delay(1000);
}