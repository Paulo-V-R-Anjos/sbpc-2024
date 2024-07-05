int azul = 9;//Atribui o valor 9 a variável azul
int verde = 10;//Atribui o valor 10 a variável verde
int vermelho = 12;//Atribui o valor 12 a variável vermelho

const int buzzer = 6; //buzzer to arduino pin 6
#define pirPin 7
#include "pitches.h"

// Create variables:
int val = 0;
bool motionState = false; // We start with no motion detected.

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(azul, OUTPUT);//Define a variável azul como saída
  pinMode(verde, OUTPUT);//Define a variável verde como saída
  pinMode (vermelho, OUTPUT);//Define a variável vermelho como saída
  pinMode(pirPin, INPUT); // motion dude
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  Vermelho();//Função para acionamento na cor vermelha
  Verde();//Função para acionamento na cor verde
  Azul();//Função para acionamento na cor azul
  Branco();//Função para acionamento na cor branca
  Magenta();//Função para acionamento na cor magenta
  Amarelo();//Função para acionamento na cor amarela
  Ciano();//Função para acionamento na cor ciano

  // motion/buzzer part of the code
  val = digitalRead(pirPin);
  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(buzzer, melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
    // Change the motion state to true (motion detected):
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }
  // If no motion is detected (pirPin = LOW), do the following:
  else {
    noTone(buzzer); 
    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }
}

void Vermelho() {
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto, ligando-o
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Verde() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Azul() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Branco() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  digitalWrite(verde, HIGH);//Coloca verde em nível alto, ligando-o
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Magenta() {
  digitalWrite(azul, HIGH);//Coloca azul em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(azul, LOW);//Coloca azul em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Amarelo() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  digitalWrite(vermelho, HIGH);//Coloca vermelho em nível alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  digitalWrite(vermelho, LOW);//Coloca vermelho em nível baixo
  delay(1000);//Intervalo de 1 segundo
}
void Ciano() {
  digitalWrite(verde, HIGH);//Coloca verde em nível alto
  digitalWrite(azul, HIGH);//Coloca azul em nível baixo alto
  delay(1000);//Intervalo de 1 segundo
  digitalWrite(verde, LOW);//Coloca verde em nível baixo
  digitalWrite(azul, LOW);//Coloca azul  em nível baixo
  delay(1000);//Intervalo de 1 segundo
}