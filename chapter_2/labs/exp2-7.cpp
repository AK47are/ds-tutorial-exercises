#include <iostream>

#include "../../docs/lib/include/linklist.h"

int main() {
  linklist<int> ha{1, 3, 4, 5, 6}, hb{5, 4, 2, 12, 3, 4, 11, 11, 11};
  linklist<int> m;
  m.merge(ha, hb);
  std::cout << m << "\n";
}
