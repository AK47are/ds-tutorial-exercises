#include <iostream>

#include "../../docs/include/SqString.hpp"

int* GetNext(const SqString& s) {
  int* next = new int[s.Size()];
  next[0] = -1;
  int i = 0, j = -1;
  while (i < s.Size())
    if (j == -1 || s[j] == s[i]) {
      ++i, ++j;
      next[i] = j;
    } else {
      j = next[j];
    }
  return next;
}

int* GetNextval(const SqString& s) {
  int* nextval = new int[s.Size()];
  nextval[0] = -1;
  int i = 0, j = -1;
  while (i < s.Size())
    if (j == -1 || s[j] == s[i]) {
      ++i, ++j;
      nextval[i] = (s[j] != s[i]) ? j : nextval[j];
    } else {
      j = nextval[j];
    }
  return nextval;
}

long Find(const SqString& master, const SqString& str, int* next) {
  int i = 0, j = 0;
  while (i < master.Size() && j != str.Size()) {
    if (j == -1 || master[i] == str[j]) {
      ++i, j++;
    } else {
      j = next[j];
    }
  }
  if (j == str.Size()) return i - j;
  return -1;
}

int main() {
  using namespace std;
  SqString s{"abcabcdabcdeabcdefabcdefg"};
  SqString t{"abcdeabcdefab"};
  long res;
  cout << "s: " << s << "\nt: " << t << "\n";
  for (int i = 0; i + t.Size() <= s.Size(); ++i) {
    res = 1;
    for (int j = 0; j < t.Size(); ++j) {
      if (s[i + j] != t[j]) {
        res = 0;
        break;
      }
    }
    if (res == 1) {
      cout << "匹配成功，index 为 " << i << "\n";
      break;
    }
  }
  if (res == 0) {
    cout << "匹配失败!\n";
  }
  int* next = GetNext(t);
  cout << "t 的 next 数组为：";
  for (int i = 0; i < t.Size(); ++i) {
    cout << next[i];
  }
  cout << "\n";
  res = Find(s, t, next);
  if (res == -1) {
    cout << "匹配失败!\n";
  } else {
    cout << "匹配成功，index 为 " << res << "\n";
  }
  delete[] next;
  int* nextval = GetNextval(t);
  cout << "t 的 nextval 数组为：";
  for (int i = 0; i < t.Size(); ++i) {
    cout << nextval[i];
  }
  cout << "\n";
  res = Find(s, t, nextval);
  if (res == -1) {
    cout << "匹配失败!\n";
  } else {
    cout << "匹配成功，index 为 " << res << "\n";
  }
  delete[] nextval;
}
