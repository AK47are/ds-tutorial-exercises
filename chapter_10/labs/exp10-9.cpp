#include <numeric>

#include "sort.hpp"

int Digit(int num, int exp) { return (num / exp) % 10; }

void CountSortDigit(vector<int>& a, const int exp) {
  int count[10];
  fill(count, count + 10, 0);
  for (auto value : a) ++count[Digit(value, exp)];
  // for (auto value : count) cout << value << " ";
  // cout << "\n";
  int prefix[10];
  fill(prefix, prefix + 10, 0);
  partial_sum(count, count + 10, prefix);
  // for (auto value : prefix) cout << value << " ";
  // cout << "\n";
  vector<int> tmp(a.size());
  for (auto value = a.rbegin(); value != a.rend(); ++value) {
    // cout << Digit(*value, exp) << "Digit\n";
    // cout << prefix[Digit(*value, exp)]-- << "\n";
    tmp[prefix[Digit(*value, exp)] - 1] = *value;
    prefix[Digit(*value, exp)]--;
  }
  a.swap(tmp);
}

void RadixSort(vector<int>& a) {
  auto min = min_element(a.begin(), a.end());
  if (*min < 0) return;  // 不考虑负数。
  auto max = max_element(a.begin(), a.end());
  int exp;
  for (exp = 1; exp < *max; exp *= 10) {
    CountSortDigit(a, exp);
  }
  // 一打印 *max 会程序结果会错误。原因未知。
  // cout << *max << "\n";
  // cout << exp << "\n";
}

int main() { TestSort(RadixSort); }
