#include <iostream>

#include "../../docs/lib/include/LinkList.h"

int main() {
  LinkList<char> h{'a', 'b', 'c', 'd', 'e'};
  std::cout << h << "\nSize: " << h.Size() << "\n"
            << "Empty: " << h.IsEmpty() << "\n"
            << "The third element: " << h.Begin()->next->next->data << "\n";
  int a_index = 0;
  for (auto cur = h.Begin(); cur->data != 'a' && cur != h.End();
       cur = cur->next)
    ++a_index;
  std::cout << "a index: " << a_index << "\n"
            << h.Insert('f', 3) << "\n"
            << h.Erase(2) << "\n";
}
