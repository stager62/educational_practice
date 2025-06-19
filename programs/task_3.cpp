#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  int command = 0;
  int first_value = 0;
  int second_value = 0;
  int* sum_arr = new int[k];
  int position_arr = 0;
  std::cin >> n >> k;
  int* amount_precipitation = new int[n]; //массив для хранения снега

//обрабатываем событие, если 1 - доавляем снег, если 2 - заносим сумму в массив, чтобы в конце вывести
  for (int i = 0; i < k; i = i + 1) {
    std::cin >> command;
    if (command == 1) {
      std::cin >> first_value >> second_value;
      amount_precipitation[first_value - 1] += second_value;
    } else {
      int sum = 0;
      std::cin >> first_value >> second_value;
      for (int j = first_value - 1; j < second_value; j = j + 1) {
        sum = sum + amount_precipitation[j];
      }
      sum_arr[position_arr] = sum;
      position_arr = position_arr + 1;
    }
  }

//выводим все наши запросы (2)
  for (int i = 0; i < position_arr; i = i + 1) {
    std::cout << sum_arr[i] << std::endl;
  }

//чистим память
  delete[] amount_precipitation;
  delete[] sum_arr;
  return 0;
}