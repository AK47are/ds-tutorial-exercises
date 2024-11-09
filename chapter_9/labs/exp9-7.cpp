#include <climits>

#include "dependency.h"

int main() {
  const int size = 7;
  // 默认 keys1 大小小于等于 keys2 。
  int keys1[size + 2] = {INT_MIN, 1, 3, 5, 7, 9, INT_MAX};
  int keys2[size + 2] = {INT_MIN, 2, 4, 6, 8, 10, INT_MAX};

  int low = 0, high = size - 1, mid;
  while (low != high) {
    mid = (low + high + 1) / 2;
    if (keys1[mid] > keys2[size - mid - 1])
      high = mid - 1;
    else
      low = mid;
  }

  // cout << low << "\n";
  int num1 = ((keys1[low] < keys2[size - low - 2]) ? keys2[size - low - 2]
                                                   : keys1[low]);
  int num2;
  if (low + 1 > size + 2)
    num2 = keys2[size - low - 1];
  else
    num2 = (keys1[low + 1] < keys2[size - low - 1]) ? keys1[low + 1]
                                                    : keys2[size - low - 1];
  cout << "中位数为 " << float(num1 + num2) / 2 << "\n";
}
