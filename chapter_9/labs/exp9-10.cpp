#include "dependency.h"

int main() {
  int arr[12] = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};
  BSTree t = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};
  double suclen = 0;
  for (int i = 0; i < 12; ++i) {
    suclen += t.Depth(t.Find(arr[i])) + 1;
  }
  cout << "查找成功 ASL : " << suclen / t.Size() << "\n";
  double faillen = 0;
  int m = 0;
  for (int i = 0; i < 12; ++i) {
    auto cur = t.Find(arr[i]);
    if (!cur->left) {
      ++m;
      faillen += t.Depth(cur) + 1;
    }
    if (!cur->right) {
      ++m;
      faillen += t.Depth(cur) + 1;
    }
  }
  cout << "查找失败 ASL : " << faillen / m << "\n";
}
