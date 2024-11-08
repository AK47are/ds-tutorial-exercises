#include "dependency.h"

int main() {
  // arr[0] 是一个哨兵结点。
  int arr[11] = {5, 3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
  int i = 10;
  while (arr[i] != 5) --i;
  if (i == 0)
    cout << "Error!\n";
  else
    cout << i << "\n";
}
