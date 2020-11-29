// прерывание на нажатие кнопки. смена состояния флага
// датчик PIR припаян к платке digispark следующим образом:
// PIR          digispark
// GND    ---   GND
// SIG    ---   P2
// VCC    ---   5v

#include "DigiKeyboard.h"
volatile bool FLAG = 0; // state up/down.
volatile uint32_t milsLast;
void setup() {
  pinMode(1, OUTPUT); //LED
  digitalWrite(1,0);  // выкл.
  pinMode(2, INPUT_PULLUP);
  DigiKeyboard.sendKeyStroke(0);
  // поехали командовать!
  DigiKeyboard.delay(3000);// при втыкании - подождать.
  DigiKeyboard.sendKeyStroke(KEY_F3, MOD_ALT_RIGHT | MOD_CONTROL_LEFT);
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("login"); // логин пользователя от имени которого слать сообщения
  DigiKeyboard.delay(500);
  DigiKeyboard.println("password"); // пароль тоже заменить.
  DigiKeyboard.delay(4000);
  
  attachInterrupt(0, btnInterr, FALLING); // прерывание P2 INT0
}

void loop() {
  DigiKeyboard.delay(50);
  if (FLAG) {
    // обработка события.
    digitalWrite(1,1);  // раз уж они есть, будем моргать.
    DigiKeyboard.println("tg4all -pir");  // команда запуска скрипта. Если не в /bin, то указать путь до tg4all
    DigiKeyboard.delay(100);
    FLAG = !FLAG;
    digitalWrite(1,0);
  }
  DigiKeyboard.delay(100);
}

void btnInterr() {
  if (millis() - milsLast > 30000){
    milsLast = millis(); // засекли время - игнорим всё остальное.
    FLAG = !FLAG;
  } // Остальные обращения к прерыванию - считаем лишним дребезгом в течении 30000ms=30sec
}
// END
