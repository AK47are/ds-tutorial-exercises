#include <iostream>

#include "../../docs/include/SqString.hpp"

int main() {
  using namespace std;
  SqString s{"abcdefghijklmn"};
  SqString s1{"xyz"};
  cout << s << "\n"
       << "Length: " << s.Size() << "\n";
  SqString s2 = s;
  cout << s2.Insert(s1, 9) << "\n";
  s2 = s;
  cout << s2.Erase(1, 6) << "\n";
  s2 = s;
  cout << s2.Replace(s1, 1) << "\n"
       << s.GetSubStr(2, 10) << "\n"
       << s1.Insert(s2, s1.Size()) << "\n";
  cout << s2.Find("lmn") << "\n";
}
