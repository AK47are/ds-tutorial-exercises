#include <iostream>

#include "../../docs/include/LinkString.hpp"

int main() {
  using namespace std;
  LinkString s{"abcdefghijklmn"};
  LinkString s1{"xyz"};
  cout << s << "\n"
       << "Length: " << s.Size() << "\n";
  LinkString s2 = s;
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