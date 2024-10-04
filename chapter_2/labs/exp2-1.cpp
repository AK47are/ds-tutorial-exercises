#include <iostream>

#include "../../docs/lib/include/SqList.h"
using namespace std;

int main() {
  SqList<char, 10> a{'a', 'b', 'c', 'd', 'e'};
  cout << a << "\n";
  cout << "Length: " << a.Size() << "\n";
  cout << "Isempty: " << a.IsEmpty() << "\n";
  cout << "The third element: " << a[2] << "\n";
  int i = 0;
  while (a[i] != 'a') ++i;
  cout << "a index is " << i << "\n";
  a.Insert('f', 3);
  cout << a << "\n";
  a.Erase(2);
  cout << a << "\n";
}
