#include <array>

#include "dependency.h"

struct IdxType {
  int max_key;
  int index;
};

int main() {
  array arr = {8,  14, 6,  9,  10, 22, 34, 18,  19, 31, 40, 38, 54,
               66, 46, 71, 78, 68, 80, 85, 100, 94, 88, 96, 87};
  IdxType idx_table[5];
  for (int i = 0; i < arr.size(); i += 5) {
    idx_table[i / 5].index = i;
    idx_table[i / 5].max_key = 0;
    for (int j = 0; j < 5; ++j) {
      if (i + j == arr.size()) break;
      if (idx_table[i / 5].max_key < arr[i + j])
        idx_table[i / 5].max_key = arr[i + j];
    }
  }
  int head = 0, end = 4, key = 46;
  // 寻找最大上界。
  while (head != end) {
    int mid = (head + end) / 2;
    // cout << head << " " << end << "\n";
    // cout << mid << " max_key: " << idx_table[mid].max_key << "\n";
    if (idx_table[mid].max_key < key)
      head = mid + 1;
    else
      end = mid;
  }

  for (int i = 0; i < 5; ++i) {
    if (arr[idx_table[end].index + i] == key)
      cout << key << " 的下标为：" << idx_table[end].index + i << "\n";
  }
}
