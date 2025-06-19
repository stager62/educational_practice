#include <iostream>

int main() {
//инициализируем переменные
  int n = 0;
  int a = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  std::cin >> n;
  int* result = new int[n];

//считаем и записываем результаты, b_y нет, так как он равен 0
  for (int i = 0; i < n; i = i + 1) {
    std::cin >> a >> b >> x >> y;
    int b_x = std::min(b, x);
    int a_x = std::min(a, x - b_x);
    int a_y = std::min(a - a_x, y);
    result[i] = b_x + a_x + a_y;
  }

  for (int i = 0; i < n; i = i + 1) {
    std::cout << result[i] << " ";
  }
  return 0;
}