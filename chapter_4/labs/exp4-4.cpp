#include <iostream>

#include "../../docs/include/SqString.hpp"
int main() {
  using namespace std;
  SqString key{"abcdefghijklmnopqrstuvwxyz"};
  SqString value{"ngzqtcobmuhelkpdawxfyivrsj"};
  char str[50];
  cout << "输入字符串：";
  cin >> str;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (isalpha(str[i]))
      for (int j = 0; j < key.Size(); ++j) {
        if (str[i] == key[j]) str[i] = value[j];
      }
  }
  cout << "加密后：" << str << "\n";
}
