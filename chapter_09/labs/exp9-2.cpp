#include "dependency.h"

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int head = 0, end = 9, key = 1;
  while (head != end) {
    int mid = (head + end) / 2;
    if (arr[mid] < key)
      head = mid + 1;
    else
      end = mid - 1;
  }
  if (arr[head] != key)
    cout << "没有找到！\n";
  else
    cout << key << " 的索引为：" << head << "\n";
}
