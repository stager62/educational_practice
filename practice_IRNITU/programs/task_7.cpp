#include <iostream>

int main() {
//заводим переменные для проверки
  std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string numbers = "0123456789";
  std::string car_number;
  std::cin >> car_number;
  
//проверяем вхождения, если все правильно выводим yes
  if (letters.find(car_number[0]) != - 1 && letters.find(car_number[4]) != - 1 && letters.find(car_number[5]) != - 1) {
    if (numbers.find(car_number[1]) != - 1 && numbers.find(car_number[2]) != - 1 && numbers.find(car_number[3]) != - 1){
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  } else {
    std::cout << "NO";
  }
  return 0;
}