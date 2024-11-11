#include <cstdlib>
#include <ctime>
#include <vector>

#include "sort.hpp"

int main() {
  srand(time(0));
  const int n = 50000;
  vector<int> arr(n);
  for (auto& value : arr) value = rand() % 99 + 1;
  vector<int> tmp = arr;

  clock_t start_time = clock();
  ISort(tmp);
  clock_t end_time = clock();
  cout << "直接插入排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  BISort(tmp);
  end_time = clock();
  cout << "折半插入排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  ShellSort(tmp);
  end_time = clock();
  cout << "希尔排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  BubbleSort(tmp);
  end_time = clock();
  cout << "冒泡排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  QuickSort(tmp);
  end_time = clock();
  cout << "快速排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  SelectSort(tmp);
  end_time = clock();
  cout << "简单选择排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  HeapSort(tmp);
  end_time = clock();
  cout << "堆排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  tmp = arr;
  start_time = clock();
  MergeSort(tmp);
  end_time = clock();
  cout << "二路归并排序： " << (double)(end_time - start_time) / CLOCKS_PER_SEC
       << " seconds." << endl;

  return 0;
}
