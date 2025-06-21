// указываем порты (пины)
#define PHOTO_PIN A0 // фоторезистор
#define GREEN_LED 2 // зеленый светодиод
#define RED_LED 3 // красный светодиод
#define THRESHOLD 512 // пороговое значение для открытия дверей
#define DELAY_TIME 3000 // время открытия дверей

void setup() {
  pinMode(GREEN_LED, OUTPUT); // пин для зеленого
  pinMode(RED_LED, OUTPUT); // пин для красного
  Serial.begin(9600); // инициализация для ввода вывода (передача данных)
  digitalWrite(RED_LED, HIGH); // по умолчанию двери закрыты
  Serial.println("Двери закрыты");
}

void loop() {
  int sensorValue = analogRead(PHOTO_PIN); // чтение значения фоторезистора

  // Serial.print("Значение датчика: "); // выводим значение датчика (в целом нам это не нужно)
  // Serial.println(sensorValue);

  if (sensorValue > THRESHOLD) { // проверяем нужно ли открыть дверь
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("Двери открываются");
    delay(DELAY_TIME);
    sensorValue = analogRead(PHOTO_PIN); // проверяем нужно ли закрыть дверь
    if (sensorValue <= THRESHOLD) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      Serial.println("Двери закрываются");
    }
  }
}