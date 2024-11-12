#include <algorithm>

#include "dependency.h"
const int k = 5;

// 简单认为可以读取 k 个记录，败者树不占用内存且不考虑输出情况。
void RepSelSort(vector<vector<int>>& block, vector<int>& data) {
  block.push_back(vector<int>());
  vector<int> input;

  if (data.size() < k) {
    input = vector<int>(data.begin(), data.end());
    sort(input.begin(), input.end());
    block[0].swap(input);
    return;
  }

  auto cur = data.begin() + k + 1;
  int leave[k];
  copy(data.begin(), data.end(), leave);
  LoseTree<k, int, INT_MAX, greater<int>> t(leave);
  while (!t.IsEmpty()) {
    int min = t.Top();
    if (block.back().size() != 0 && block.back().back() > min)
      block.push_back(vector<int>());
    block[block.size() - 1].push_back(min);
    if (cur != data.end())
      t.Pop(*cur++);
    else
      t.Pop();
  }
}

int main() {
  vector<int> arr = {15, 4,  97, 64, 17, 32, 108, 44,  76,
                     9,  39, 82, 56, 31, 80, 73,  255, 68};

  vector<vector<int>> block;
  RepSelSort(block, arr);
  cout << "得到初始块：\n";
  for (const auto& cur : block) {
    for (const auto& value : cur) {
      cout << value << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
