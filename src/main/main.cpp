#include <Arduino.h>
#include <SparkFun_TB6612.h>
#include "controle_juiz.h"


// Pinos do motor
#define AIN1 25
#define BIN1 27
#define AIN2 33
#define BIN2 14
#define PWMA 32
#define PWMB 13
#define STBY 26

// Pino do IR
#define IR_PIN 19

// Definição de comandos do controle (Fazer testes no examples/IR pra incrementar mais botões e ajusta-los)
#define ONE 0
#define TWO 1
#define TREE 2

// Objeto IR
controle_juiz controle(IR_PIN);

// Objeto Motores
Motor rightMotor(AIN1, AIN2, PWMA, 1, STBY);
Motor leftMotor(BIN1, BIN2, PWMB, 1, STBY);

void setup() {

  Serial.begin(112500);
  controle.init();
}
void loop() {
  int read_ir = controle.read();

  switch (read_ir) {
    case ONE:
      leftMotor.drive(255);
      rightMotor.drive(-255);
      delay(200);

      break;
    
    case TWO:
      leftMotor.drive(-255);
      rightMotor.drive(255);
      delay(200);

      break;

    case TREE:
      leftMotor.drive(255);
      rightMotor.drive(255);
      delay(200);

      break;
  }
   
}