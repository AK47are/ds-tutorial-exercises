#include "dependency.h"

int lower_bound(const int arr[], const int& n, const int& target) {
  int low = 0, high = n - 1;
  while (low != high) {
    int mid = (low + high) / 2;
    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid;
  }
  if (arr[low] != target)
    return -1;
  else
    return low;
}

// 注意这个和 C++ 自带的 upper_bound 不一样。
int upper_bound(const int arr[], const int& n, const int& target) {
  int low = 0, high = n - 1;
  while (low != high) {
    // 由于截断，所以要额外加 1 。
    int mid = (low + high + 1) / 2;
    if (arr[mid] > target)
      high = mid - 1;
    else
      low = mid;
  }
  if (arr[high] != target)
    return -1;
  else
    return high;
}

int main() {
  int arr[10] = {1, 2, 3, 3, 3, 3, 3, 8, 9, 10};
  int key = 3;
  int lb = lower_bound(arr, 10, key);
  int ub = upper_bound(arr, 10, key);
  cout << "[" << lb << ", " << ub << "]\n";
}
