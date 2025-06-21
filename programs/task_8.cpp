#include <LedControl.h> // подключаем библиотеку

// указываем порты (пины)
#define DIN_PIN 11 // передача данных
#define CS_PIN  10 // выбор чипа
#define CLK_PIN 13 // тактовый сигнал

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1); // объект для управления матрицей

// массив, где хранится 3 вида сердца
const byte heartPatterns[3][8] = {
  {
    0b01100110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000
  },
  {
    0b00000000,
    0b00100100,
    0b01111110,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00011000,
    0b00111100,
    0b00011000,
    0b00000000,
    0b00000000,
    0b00000000
  }
};

void setup() {
  lc.shutdown(0, false); // включаем матрицу
  lc.setIntensity(0, 10); // устанавливаем яркость
  lc.clearDisplay(0); // чистим дисплей
}

// бесконечно отображаем все варианты сердца
void loop() {
  showHeart(0); delay(400);
  showHeart(1); delay(400);
  showHeart(2); delay(400);
  showHeart(1); delay(400);
}

// отображаем сердце на матрице (загружаем в нее строки пикселей)
void showHeart(int patternIndex) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, heartPatterns[patternIndex][row]);
  }
}