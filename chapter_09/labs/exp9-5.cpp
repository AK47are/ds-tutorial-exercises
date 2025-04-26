#include <array>

#include "dependency.h"

int main() {
  const int capacity = 13;
  LPTable<int, capacity> h;
  array arr = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
  for (int i = 0; i < arr.size(); ++i) {
    h[arr[i]] = i;
  }
  h.Show();
  cout << "查询 key = 29: " << h[29] << "\n";
  h.Delete(77);
  cout << "删除 77 :\n";
  h.Show();
  cout << "重插入 77 :\n";
  h[77] = 10;
  cout << "查询 key = 77: " << h[77] << "\n";
  h.Show();
}
