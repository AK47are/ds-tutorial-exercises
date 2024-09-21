#include <iostream>

#include "../../docs/lib/include/sqlist.h"
using namespace std;

int main() {
  sqlist<char, 10> L{'a', 'b', 'c', 'd', 'e'};
  for (int i = 0; i < L.size(); ++i) cout << " " << L[i];
  cout << "\n";
  cout << "Length: " << L.size() << "\n";
  cout << "Isempty: " << L.empty() << "\n";
  cout << "The third element: " << L[2] << "\n";
  cout << "a index is " << L.index_find('a') << "\n";
  L.insert('f', 3);
  for (int i = 0; i < L.size(); ++i) cout << " " << L[i];
  cout << "\n";
  L.erase(2);
  for (int i = 0; i < L.size(); ++i) cout << " " << L[i];
  cout << "\n";
}
