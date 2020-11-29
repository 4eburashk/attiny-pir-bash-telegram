# attiny-pir-bash-telegram
digispark atmega85 as HID keyboard + PIR + bash script for telegram messaging

tg4all - bash скрипт отправки сообщений.
В зависимости от параметра вызова, отправляет сообщение в телеграм о логине или о срабатывании PIR датчика.

История: Изначально все команды отправки сообщений в телеграм были реализованы внутри кода attiny85 но это оказалось неудобно для правки и редактирования.
На данный момент, со стороны attiny85 при срабатывании датчика движения, идёт только команда "tg4all -pir", остальную работу делает скрипт.