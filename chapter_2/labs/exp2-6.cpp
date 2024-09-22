#include <iostream>

#include "../../docs/lib/include/linklist.h"

int main() {
  linklist<int> l{5, 1, 7, 2, 4, 6, 4, 2};
  std::cout << l << "\n";
  int k = 0, x = l[0];
  for (int i = 0; i < l.size(); ++i)
    if (l[i] < x) {
      int temp = l[i];
      l[i] = l[k];
      l[k] = temp;
      k++;
      // std::cout << l << "\tk = " << k << '\n';
    }
  std::cout << l << "\n";
}
