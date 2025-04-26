#include "dependency.h"

void DeleteMin(BSTree<int>& t) {
  BtNode<int>* cur = t.GetRoot();
  while (cur->left) cur = cur->left;
  t.Erase(cur->data);
}

void DeleteMax(BSTree<int>& t) {
  BtNode<int>* cur = t.GetRoot();
  while (cur->right) cur = cur->right;
  t.Erase(cur->data);
}

int main() {
  BSTree<int> t;
  int arr[11] = {7, 9, 6, 3, -1, -2, 4, -2, -1, -2, 0};
  for (int i = 0; i < 11; ++i) {
    cout << "arr[i]: " << arr[i] << "\n";
    if (arr[i] == -1)
      DeleteMin(t);
    else if (arr[i] == -2)
      DeleteMax(t);
    else
      t.Insert(arr[i]);
    t.Show(cout, t.GetRoot(), t.InOrder);
    cout << "\n";
  }
  cout << "\n";
}
