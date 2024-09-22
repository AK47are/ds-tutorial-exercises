#include <iostream>

#include "../../docs/lib/include/dlinklist.h"

int main() {
  dlinklist<int> h{'a', 'b', 'c', 'd', 'e'};
  std::cout << h << "Size: " << h.size() << "\n"
            << "Empty: " << h.empty() << "\n"
            << "The third element: " << h[2] << "\n"
            << "a index: " << h.index_find('a') << "\n"
            << h.insert('f', 3) << "\n"
            << h.erase(2) << "\n";
}
