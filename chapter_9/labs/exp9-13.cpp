#include "dependency.h"

int main() {
  int arr[14] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int key = 5, min_index = 0;
  for (int i = 4; i < 13; i += 4) {
    if (key >= arr[i]) min_index = i;
  }
  for (int i = 0; i < 4; ++i) {
    if (key == arr[min_index + i])
      cout << "找到 key = " << key << " 的编号：" << min_index + i << "\n";
  }
  // ASL = (n + 3) / 2  size = 4 * n
  // 第一次使用折半查找。 log_2{n} + 1
}
