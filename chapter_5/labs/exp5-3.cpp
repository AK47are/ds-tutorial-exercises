#include <iostream>

#include "dependency.h"

using namespace std;
void Find(SqString str, int begin) {
  if (str.Find(".", 3) != -1) {
    if (str.Size() - begin - 1 < 3) {
      int temp = 0;
      for (int i = 0; i < str.Size() - begin - 1; ++i)
        temp *= 10, temp += str[begin + i] - '0';
      if (temp <= 255) cout << str << "\n";
    }
    return;
  }
  // cout << str << " " << begin << "OK\n";
  int temp = 0;
  for (int i = 0; i < 3; ++i) {
    temp *= 10, temp += str[begin + i] - '0';
    if (temp <= 255) {
      str.Insert('.', begin + i + 1);
      // cout << str << " " << temp << "\n";
      Find(str, begin + i + 2);
      str.Erase(begin + i + 1);
    }
  }
}

int main() {
  SqString str{"25525511135"};
  Find(str, 0);
}
