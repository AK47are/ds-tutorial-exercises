#include "dependency.h"

int main() {
  const int K = 5;
  const int k = 7;
  vector<int> arr = {15, 4,  97, 64, 17, 32, 108, 44,  76,
                     9,  39, 82, 56, 31, 80, 73,  255, 68};
  Heap<int> h;
  for (int i = 0; i < K; ++i) h.Push(arr[i]);
  for (int i = K; i < arr.size(); ++i) {
    if (arr[i] < h.Top()) {
      h.Pop();
      h.Push(arr[i]);
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << h.Top() << " ";
    h.Pop();
  }
  cout << "\n";
}
