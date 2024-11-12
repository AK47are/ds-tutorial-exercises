#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <algorithm>
#include <functional>
#include <initializer_list>

#include "../list/DynList.hpp"
template <typename T, typename Comp = std::less<int>>
class Heap {
 private:
  DynList<T> arr_;
  Comp compare_;

 protected:
  int Left(const int& i) const { return i * 2 + 1; }
  int Right(const int& i) const { return i * 2 + 2; }
  int Parent(const int& i) const { return (i - 1) / 2; }
  void HeapUp(int i) {
    int prev = -1;
    while (prev != i) {
      if (compare_(arr_[Parent(i)], arr_[i])) {
        std::swap(arr_[Parent(i)], arr_[i]);
        prev = i;
        i = Parent(i);
      } else {
        break;
      }
    }
  }

  void HeapDown(int i) {
    while (true) {
      int l = Left(i), r = Right(i), res = i;
      // 很巧妙。
      if (l < Size() && compare_(arr_[res], arr_[l])) res = l;
      if (r < Size() && compare_(arr_[res], arr_[r])) res = r;
      if (res == i) break;
      std::swap(arr_[i], arr_[res]);
      i = res;
    }
  }

 public:
  Heap() = default;
  Heap(std::initializer_list<T> li) : arr_(li) {
    for (int i = parent(Size() - 1); i >= 0; i--) {
      HeapDown(i);
    }
  }

  int Size() const { return arr_.Size(); };
  void Push(const T& data) {
    arr_.Insert(data, arr_.Size());
    HeapUp(arr_.Size() - 1);
  }
  void Pop() {
    std::swap(arr_[0], arr_[Size() - 1]);
    arr_.Erase(Size() - 1);
    HeapDown(0);
  };

  T Top() const { return arr_[0]; };
};

#endif
