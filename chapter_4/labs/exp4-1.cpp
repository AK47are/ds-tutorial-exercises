#include <iostream>

#include "../../docs/include/SqString.hpp"

int main() {
  using namespace std;
  SqString s{"abcdefghijklmn"};
  SqString s1{"xyz"};
  cout << s << "\n"
       << "Length: " << s.Size() << "\n";
  SqString s2 = s;
  s2.Insert(s1, 9);
  cout << s2 << "\n";
  s2 = s;
  s2.Erase(1, 6);
  cout << s2 << "\n";
  s2 = s;
  s2.Replace(s1, 1);
  cout << s2 << "\n";
  s.GetSubStr(2, 10);
  cout << s << "\n";
  s1.Insert(s2, s1.Size());
  cout << s1 << "\n";
  cout << s2.Find("lmn") << "\n";
}
