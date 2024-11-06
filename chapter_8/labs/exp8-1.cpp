#include "dependency.h"

int main() {
  int edges[6][6] = {{INT_MAX, 5, INT_MAX, 7, INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX},
                     {8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9},
                     {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, 6},
                     {INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
                     {3, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX}};
  MatGraph m(edges);
  m.Show();
  cout << "\n";
  AdjGraph g(edges);
  g.Show();
}
