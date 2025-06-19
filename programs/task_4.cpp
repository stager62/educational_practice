#include <iostream>
#include <vector>
#include <string>

int main() {
//инициализируем переменные
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> permutation(n);
  for (int i = 0; i < n; i = i + 1) {
    std::cin >> permutation[i];
  }
  std::string encrypted_word;
  std::cin >> encrypted_word;
  std::string original_word = encrypted_word;

//делаем перестановку k раз, ставя буквы на место из permutation
  for (int i = 0; i < k; i = i + 1 ) {
    for (int j = 0; j < n; j = j + 1) {
      original_word[permutation[j] - 1] = encrypted_word[j];
    }
    encrypted_word = original_word;
  }

  std::cout << original_word;
  return 0;
}