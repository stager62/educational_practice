#include <iostream>
#include <vector>

int main() {
//инициализируем переменные
  int h = 0;
  int w = 0;
  std::cin >> h >> w;
  std::vector<std::vector<int>> matrix (h, std::vector<int>(w));
  for (int i = 0; i < h; i = i + 1) {
    for (int j = 0; j < w; j = j + 1) {
      std::cin >> matrix[i][j];
    }
  }

//обозначем границы как максимальные
  int top = h;
  int bottom = -1;
  int right = -1;
  int left = w;

//находим 1 и вычисляем границы
  for (int i = 0; i < h; i = i + 1) {
    for ( int j = 0; j < w; j = j + 1) {
      if (matrix[i][j] == 1) {
        top = std::min(top,i);
        left = std::min(left,j);
        bottom = std::max(bottom,i);
        right = std::max(right,j);
      }
    }
  }

//выводим результат, учитывая, что в программе мы нашли углы, где есть 1
  std::cout << top - 1 << " " << left - 1 << " "  << bottom + 1 << " "  << right + 1;
  return 0;
}