#include <iostream>

#include "dependence.h"

int main() {
  CLinkList<char> h{'a', 'b', 'c', 'd', 'e'};
  std::cout << h << "\nSize: " << h.Size() << "\n"
            << "Empty: " << h.IsEmpty() << "\n"
            << "The third element: " << h.PrevNode(h.Begin(), 3)->data << "\n";
  int a_index = 0;
  for (auto cur = h.Begin(); cur->data != 'a' && cur != h.End();
       cur = cur->next)
    ++a_index;
  std::cout << "a index: " << a_index << "\n"
            << h.Insert('K', 3) << "\n"
            << h.Erase(2) << "\n";
}
