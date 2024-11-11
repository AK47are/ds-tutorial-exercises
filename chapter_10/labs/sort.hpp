#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#include "../../docs/include/tree/Heap.hpp"
using namespace std;

template <typename T>
void TestSort(void (*Sort)(vector<T>&)) {
  ifstream fin("test.txt");
  int t;
  fin >> t;
  vector<vector<T>> a(t);
  for (int i = 0; i < t; ++i) {
    T m;
    fin >> m;
    a[i].resize(m);
    for (auto& value : a[i]) fin >> value;
  }
  for (int i = 0; i < a.size(); ++i) {
    cout << "原数组：";
    for (auto value : a[i]) cout << value << " ";
    cout << "\n";
    Sort(a[i]);
    cout << "排序后：";
    for (auto value : a[i]) cout << value << " ";
    cout << "\n\n";
  }
}

template <typename T>
void ISort(vector<T>& a) {
  for (int i = 1; i < a.size(); ++i) {
    int j = i;
    while (0 < j && a[j - 1] > a[j]) {
      swap(a[j - 1], a[j]);
      --j;
    }
  }
}

template <typename T>
void BISort(vector<T>& a) {
  for (int i = 1; i < a.size(); ++i) {
    auto cur = upper_bound(a.begin(), a.begin() + i, a[i]);
    a.insert(cur, a[i]);
    a.erase(a.begin() + i + 1);
  }
}

template <typename T>
void ShellSort(vector<T>& a) {
  int increment = a.size() / 2;
  while (increment != 0) {
    for (int i = increment; i < a.size(); ++i) {
      int tmp = a[i], j = i - increment;
      while (0 <= j && tmp < a[j]) {
        a[j + increment] = a[j];
        j -= increment;
      }
      a[j + increment] = tmp;
    }
    increment /= 2;
  }
}

template <typename T>
void BubbleSort(vector<T>& a) {
  for (int i = 0; i < a.size() - 1; ++i) {
    for (int j = 0; j < a.size() - i - 1; ++j) {
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
  }
}

template <typename T>
void QuickSort(T a[], int size) {
  if (size <= 1) return;
  swap(a[0], a[size / 2]);
  int low = 0, high = size - 1;
  while (low < high) {
    while (high > low && a[high] >= a[0]) --high;
    while (low < high && a[low] <= a[0]) ++low;
    swap(a[low], a[high]);
  }
  swap(a[0], a[low]);
  QuickSort(a, low);
  QuickSort(a + low + 1, size - low - 1);
}

template <typename T>
void QuickSort(vector<T>& a) {
  T arr[a.size()];
  copy(a.begin(), a.end(), arr);
  QuickSort(arr, a.size());
  copy(arr, arr + a.size(), a.begin());
}

template <typename T>
void SelectSort(vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) {
    auto min = min_element(a.begin() + i, a.end());
    swap(*min, a[i]);
  }
}

template <typename T>
void HeapSort(vector<T>& a) {
  Heap<T, greater<T>> h;
  for (auto value : a) h.Push(value);
  for (auto& value : a) {
    value = h.Top();
    h.Pop();
  }
}

template <typename T>
void Merge(T a[], int size) {
  T tmp[size];
  int top = 0;
  int l = 0, r = size / 2;
  while (true) {
    if (l < size / 2 && a[l] <= a[r])
      tmp[top++] = a[l++];
    else if (r < size && a[r] <= a[l])
      tmp[top++] = a[r++];
    else
      break;
  }
  while (l < size / 2) tmp[top++] = a[l++];
  while (r < size) tmp[top++] = a[r++];
  copy(tmp, tmp + size, a);
}

template <typename T>
void MergeSort(T a[], int size) {
  if (size <= 1) return;
  MergeSort(a, size / 2);
  MergeSort(a + size / 2, size - size / 2);
  Merge(a, size);
}

template <typename T>
void MergeSort(vector<T>& a) {
  T arr[a.size()];
  copy(a.begin(), a.end(), arr);
  MergeSort(arr, a.size());
  copy(arr, arr + a.size(), a.begin());
}
