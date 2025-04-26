// 第一种方法算法复杂度O(n^2)
#include <chrono>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double>;

void method_1(long n) {
  auto start = Clock::now();
  int number = 0;
  for (int i = 2; i < n; ++i) {
    bool isPrime = 1;
    for (int j = 2; j < i; ++j)
      if (i % j == 0) isPrime = 0;
    if (isPrime == 1) ++number;
  }
  auto end = Clock::now();
  Duration duration = end - start;
  std::cout << "Execution time: " << duration.count() << " s" << std::endl;
  std::cout << "Prime number: " << number << std::endl;
}

// 第二种方法算法复杂度O(n^1.5)
void method_2(long n) {
  auto start = Clock::now();
  std::vector<int> prime;
  for (int i = 2; i < n; ++i) {
    bool isPrime = 1;
    for (int j = 0; j < prime.size() && prime[j] < static_cast<int>(i); ++j) {
      if (i % prime[j] == 0) isPrime = 0;
    }
    if (isPrime == 1) {
      // std::cout << i << " ";
      prime.push_back(i);
    }
  }
  auto end = Clock::now();
  Duration duration = end - start;
  std::cout << "Execution time: " << duration.count() << " s" << std::endl;
  std::cout << "Prime number: " << prime.size() << std::endl;
}

int main() {
  const int n = 100000;
  // method_1(n);
  method_2(n);
}
