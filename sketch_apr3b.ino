//codigo de tranca letronica desenvolvido por https://github.com/GAabriLL


#include <SPI.h>
#include <MFRC522.h>
#include <AccelStepper.h>

#define SS_PIN   5
#define RST_PIN   27
#define IN1 12
#define IN2 14
#define IN3 26
#define IN4 25

#define ENDSTOP_PIN1 32
#define ENDSTOP_PIN2 35

MFRC522 mfrc522(SS_PIN, RST_PIN);


AccelStepper stepper(AccelStepper::FULL4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(9600); //boud
  SPI.begin();
  mfrc522.PCD_Init(); //metodo PCD_init
  stepper.setMaxSpeed(470);
  stepper.setAcceleration(1000);
  
  pinMode(ENDSTOP_PIN1, INPUT);
  pinMode(ENDSTOP_PIN2, INPUT);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
}
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
}

  Serial.print("Tag RFID detectada: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
}

  int tagValue = mfrc522.uid.uidByte[0] * 1000000 + mfrc522.uid.uidByte[1] * 10000 + mfrc522.uid.uidByte[2] * 100 + mfrc522.uid.uidByte[3];
  Serial.print(", Valor do Tag RFID: ");
  Serial.println(tagValue);

  int rotation = tagValue % 200;
  int direction = tagValue / 200 % 2 == 0 ? 1 : -1;

  Serial.print("Rotação: ");
  Serial.print(rotation);
  Serial.print(", Direção: ");
  Serial.println(direction);

  //stepper.moveTo(8000);
  stepper.moveTo(-8600);
  while (digitalRead(ENDSTOP_PIN1) == HIGH) { // Aguarda o fim de curso ser acionado
    stepper.run();    
}

  stepper.setCurrentPosition(0); // Zera a posição atual do motor
  delay(2500);
  stepper.moveTo(8600);
  while (digitalRead(ENDSTOP_PIN2) == HIGH) { // Aguarda o fim de curso ser acionado
    stepper.run();
    
  }

  delay(1000);
}