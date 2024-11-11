#include <string>

#include "sort.hpp"

int main() {
  // 简化输入。
  string str[6] = {"while", "if", "if-else", "do-while", "for", "case"};
  cout << "排序前：\n";
  for (auto value : str) cout << value << "\n";
  cout << "\n";
  QuickSort(str, 6);
  cout << "排序后：\n";
  for (auto value : str) cout << value << "\n";
  cout << "\n";
}
