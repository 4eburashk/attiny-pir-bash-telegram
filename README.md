Суть: attiny85 притворяется HID устройством - клавиатурой.
Использована стандартная библиотека https://github.com/digistump/DigisparkArduinoIntegration/tree/master/libraries/DigisparkKeyboard
Нажатием клавиш переходим на третью консоль Ctrl+Alt+F3, логин/пароль и ждём.
При срабатывании PIR датчика движения - в консоль отправляется команда "tg4all -pir"
tg4all от имени указанного tg бота, отправляет сообщение в указаный телеграм чат. 


датчик PIR (AM312) припаян к платке digispark следующим образом:
PIR          digispark
GND    ---   GND
SIG    ---   P2
VCC    ---   5v
