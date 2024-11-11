#include <numeric>
#include <string>

#include "sort.hpp"

int Index(const string& str, const int d) {
  if (d > str.size() || str[d - 1] == ' ')
    return 0;
  else
    return str[d - 1] - 'a' + 1;
}

void CountSortDigit(vector<string>& str, const int d) {
  vector<int> count(27, 0);
  for (auto s : str) ++count[Index(s, d)];
  vector<int> prefix(27, 0);
  partial_sum(count.begin(), count.end(), prefix.begin());
  vector<string> tmp(str.size());
  for (auto value = str.rbegin(); value != str.rend(); ++value) {
    tmp[prefix[Index(*value, d)] - 1] = *value;
    prefix[Index(*value, d)]--;
  }
  str.swap(tmp);
}

void RadixSort(vector<string>& str) {
  int max_length;
  for (int i = 0; i < str.size(); ++i) {
    if (max_length < str[i].size()) max_length = str[i].size();
  }
  for (int d = max_length; 0 < d; --d) {
    CountSortDigit(str, d);
  }
}

int main() {
  vector<string> str = {"while", "if", "if else", "do while", "for", "case"};
  cout << "排序前：\n";
  for (auto value : str) cout << value << "\n";
  cout << "\n";
  RadixSort(str);
  cout << "排序后：\n";
  for (auto value : str) cout << value << "\n";
  cout << "\n";
}
