#include <cmath>
#include <numeric>

#include "dependency.h"
int arr[(int)1e6];

BtNode<int>* CreateBSTree(int arr[], int size) {
  if (size == 0) return nullptr;
  BtNode<int>* root;
  root = new BtNode<int>(arr[size / 2]);
  root->left = CreateBSTree(arr, size / 2);
  root->right = CreateBSTree(arr + size / 2 + 1, (size - 1) / 2);
  return root;
}

double CalculateASL(BSTree<int>& t) {
  const int n = t.Size();
  double suclen = 0;
  for (int i = 0; i < n; ++i) {
    suclen += t.Depth(t.Find(arr[i])) + 1;
  }
  return suclen / n;
}

int main() {
  const int n = 11;
  iota(arr, arr + n, 0);
  BSTree<int> t;
  t.GetRoot() = CreateBSTree(arr, n);
  t.DispTree();
  cout << "查找成功 ASL : " << CalculateASL(t) << "\n";
  for (int i = 10; i < 1e5 + 1; i *= 10) {
    t.Delete(t.GetRoot());
    iota(arr, arr + i, 0);
    t.GetRoot() = CreateBSTree(arr, i);
    double res = CalculateASL(t);
    // 课本用的 log() 是错误的。这会导致差值越来越大。
    cout << i << "\tASL_1: " << res << "\tASL_2: " << log2(i + 1) - 1
         << "\t差值：" << res - log2(i + 1) + 1 << "\n";
  }
}
