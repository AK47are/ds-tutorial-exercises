#include "dependency.h"

bool IsLegal(int seq[], int n, const BSTree<int>& t) {
  auto cur = t.GetRoot();
  if (cur->data != seq[0]) return false;
  for (int i = 1; i < n; ++i) {
    if (cur->left && cur->left->data == seq[i]) {
      cur = cur->left;
    } else if (cur->right && cur->right->data == seq[i]) {
      cur = cur->right;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  BSTree t = {5, 2, 3, 4, 1, 6, 8, 7, 9};
  int seq[4] = {5, 6, 8, 9};
  cout << IsLegal(seq, 4, t) << "\n";
}
