#include <iostream>
#include <ostream>
int main() {
  const int n = 10;
  int sum = 0, temp = 1;
  for (int i = 1; i <= n; ++i) temp *= i, sum += temp;
  std::cout << sum << std::endl;
}
