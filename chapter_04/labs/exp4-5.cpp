#include <iostream>

#include "dependence.h"

int Find(const SqString& s, const SqString& t) {
  int num = 0;
  for (int i = 0; i + t.Size() <= s.Size(); ++i) {
    int res = 1;
    for (int j = 0; j < t.Size(); ++j) {
      if (s[i + j] != t[j]) res = 0;
    }
    if (res == 1) ++num;
  }
  return num;
}

int main() {
  using namespace std;
  const int MAX = 30;
  char str[MAX];
  cout << "输入字符串：";
  cin >> str;
  SqString s(str);
  int max_length = 0, max_index = -1;
  for (int i = 0; i < s.Size(); ++i) {
    for (int j = i + 1; j <= s.Size(); ++j) {
      // cout << s.GetSubStr(i, j) << "\n";
      if (Find(s, s.GetSubStr(i, j)) > 1)
        if (max_length < j - i) max_index = i, max_length = j - i;
    }
  }
  cout << "最大重复子串 index = " << max_index << ", length = " << max_length
       << "\n";
}
