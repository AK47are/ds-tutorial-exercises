#include <iostream>

#include "dependence.h"
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

int Find(const SqString& master, const SqString& str) {
  using namespace std;
  int* nextval = GetNextval(str);
  cout << "Nextval: ";
  for (int i = 0; i < str.Size(); ++i) {
    cout << nextval[i];
  }
  cout << "\n";
  int i = 0, j = 0, n = 0;
  while (i < master.Size()) {
    if (j == -1 || master[i] == str[j]) {
      ++i, j++;
    } else {
      cout << "匹配失败：index = " << i - j << "\ti = " << i << "\tj = " << j
           << "\t j 重设为 " << nextval[j] << "\n";
      j = nextval[j];
    }
    if (j == str.Size()) {
      cout << "匹配成功：index = " << i - j << "\ti = " << i << "\t i 重设为 ";
      i = i - j + 1;
      cout << i << "\n";
      ++n, j = 0;
    }
  }
  delete[] nextval;
  return n;
}

int main() {
  using namespace std;
  SqString s{"aaaaa"};
  SqString t{"aa"};
  cout << "主串 s：" << s << "\n";
  cout << "子串 t：" << t << "\n";
  int res = Find(s, t);
  cout << "子串 t 重叠重复次数：" << res << "\n";
}
