#include <cmath>
#include <iostream>
unsigned long long factorial(int n) {
  if (n <= 1) return 1;
  return n * factorial(n - 1);
}
int main() {
  const int n = 20;
  for (int i = 0; i < n; ++i) {
    std::cout << "i = " << i << "\t" << log2(i) << "\t" << sqrt(i) << "\t" << i
              << "\t" << i * log2(i) << "\t" << i * i << "\t" << i * i * i
              << pow(2, i) << "\t" << factorial(i) << "\n";
  }
}
