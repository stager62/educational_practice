#include <Servo.h> // подключаем библиотеку

Servo myServo; // объект для управления сервоприводом
int currentAngle = 90; // текущий угол
int targetAngle = 90; // угол, который хотим получить

void setup() {
  myServo.attach(3); // даем 3 пин сервоприводу
  Serial.begin(9600); // инициализация для ввода вывода (передача данных)
  Serial.println("Готов к работе. Введите угол (0-180):");
  myServo.write(currentAngle); // устанавливаем угол
}

void loop() {
  if (Serial.available() > 0) { // проверяем, есть ли данные в порту
    String input = Serial.readStringUntil('\n'); // читаем введенную строку
    input.trim(); // удаляем лишние пробелы (типо "55 " - не будет ошибкой)
    if (isValidNumber(input)) { // проверяем, является ли ввод числом
      targetAngle = input.toInt(); // преобразуем строку в число
      if (targetAngle >= 0 && targetAngle <= 180) { // проверяем диапазон (0-180)
        Serial.print("Поворачиваю на: ");
        Serial.println(targetAngle);
        if (targetAngle > currentAngle) { // плавный поворот сервопривода
          for (int angle = currentAngle; angle <= targetAngle; angle++) {
            myServo.write(angle);
          }
        } else { // тоже плавный поворот сервопривода
          for (int angle = currentAngle; angle >= targetAngle; angle--) {
            myServo.write(angle);
          }
        }
        currentAngle = targetAngle; // обновляем текущий угол
      } else {
        Serial.println("Ошибка: введите угол от 0 до 180!");
      }
    } else {
      Serial.println("Ошибка: введите число!");
    }
  }
}

// функция проверки, является ли строка числом (проверяет каждый символ - цифра или нет)
bool isValidNumber(String str) {
  for (char c : str) {
    if (!isdigit(c)) return false;
  }
  return true;
}