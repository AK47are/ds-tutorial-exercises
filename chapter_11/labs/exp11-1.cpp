#include "dependency.h"

int main() {
  using namespace std;
  int b[5] = {17, 5, 10, 29, 15};
  LoseTree<5, int, INT_MAX, greater<int>> tree(b);
  while (!tree.IsEmpty()) {
    cout << tree.Top() << " ";
    tree.Pop();
  }
  cout << "\n";
}
