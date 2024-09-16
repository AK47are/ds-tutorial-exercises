// 第一种方法算法复杂度O(n)
#include <chrono>
#include <iostream>
#include <ostream>
using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double, std::milli>;

void method_1(long n) {
  auto start = Clock::now();
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += n;
  auto end = Clock::now();
  Duration duration = end - start;
  std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

// 第二种方法算法复杂度O(1)
void method_2(long n) {
  auto start = Clock::now();
  int sum = n * (n + 1) / 2;
  auto end = Clock::now();
  Duration duration = end - start;
  std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

int main() {
  const long n = 10000000;
  method_1(n);
  method_2(n);
}
