#include "dependency.h"

int main() {
  const int k = 5;
  vector<vector<int>> block{{17, 21}, {5, 44}, {10, 12}, {29, 32}, {15, 56}};

  int leave[k];
  for (int i = 0; i < k; ++i) leave[i] = block[i][0];
  LoseTree<k, int, INT_MAX, greater<int>> t(leave);
  while (!t.IsEmpty()) {
    cout << t.Top() << " ";
    block[t.GetIndex()].erase(block[t.GetIndex()].begin());
    if (block[t.GetIndex()].empty()) {
      t.Pop();
    } else {
      t.Pop(block[t.GetIndex()].front());
    }
  }
  cout << "\n";
}
