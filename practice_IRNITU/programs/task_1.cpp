#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
  int n = 0;
  std::cout << "Введите высоту: ";
  std::cin >> n;
  std::srand(std::time(0)); //для рандома
  std::vector<std::vector<int>> pyramid; //создаем пирамиду

  for (int i = 0; i < n; i = i + 1) { //заполняем пирамиду рандомными значениями
    std::vector<int> row(i + 1);
    for (int j = 0; j <= i; j = j + 1) {
      row[j] = std::rand() % 100;
    }
    pyramid.push_back(row);
  }

  for (int i = 0; i < n; i = i + 1) { //выводим пирамиду
    for (int j = 0; j <= i; j = j + 1) {
      std::cout << pyramid[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::vector<std::vector<int>> dp = pyramid; //копируем пирамиду
  for (int i = n - 2; i >= 0; i = i - 1) { //используем dp для заполнения снизу вверх, вверху будет наш минимум
    for (int j = 0; j <= i; j = j + 1) {
      dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  int min_sum = dp[0][0];
  std::cout << "Минимальная сумма: " << min_sum << std::endl;
  std::vector<int> path; //для хранения пути
  path.push_back(pyramid[0][0]);
  int column = 0; //стобец в пирамие
  for (int i = 1; i < n; i = i + 1) { //ищем разницу значений в dp и в пирамиде, так мы найдем нижнего соседа
    if (dp[i - 1][column] - pyramid[i - 1][column] == dp[i][column]) {
      path.push_back(pyramid[i][column]);
    } else {
      column = column + 1;
      path.push_back(pyramid[i][column]);
    }
  }
  std::cout << "Путь: ";
  for (size_t i = 0; i < path.size(); i = i + 1) {
    std::cout << path[i] << " ";
  }
  return 0;
}