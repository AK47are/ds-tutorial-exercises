#include <iostream>

#include "dependence.h"

int main() {
  using namespace std;
  SqString s{"abcdefghijklmn"};
  SqString s1{"xyz"};
  cout << s << "\n"
       << "Length: " << s.Size() << "\n";
  SqString s2 = s;
  s2.Insert(s1, 8);
  cout << s2 << "\n";
  s2 = s;
  s2.Erase(1, 6);
  cout << s2 << "\n";
  s2 = s;
  s2.Replace(s1, 1);
  cout << s2 << "\n";
  cout << s.GetSubStr(1, 11) << "\n";
  s1.Insert(s2, s1.Size());
  cout << s1 << "\n";
}
