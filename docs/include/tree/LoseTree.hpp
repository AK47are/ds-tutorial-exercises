#ifndef LOSETREE_HPP_
#define LOSETREE_HPP_
#include <algorithm>
#include <climits>
#include <functional>

// 默认败者为更小的值，K 路归并。INT_MIN 代表无值。
// 如果用堆进行 k 路归并，需要将数据和索引绑定。
// 相较于堆，将数据与索引的逻辑分离，比较次数少一倍，占用空间更多。
template <int K, typename T = int, T NoValue = INT_MIN,
          typename Comp = std::less<T>>
class LoseTree {
 private:
  int ls_[K];
  T* leave_;
  Comp compare_;

 public:
  LoseTree(T record[K]) : leave_(record) {
    int index = std::max_element(record, record + K, compare_) - record;
    std::fill(ls_, ls_ + K, index);
    for (int i = K - 1; 0 <= i; --i) {  // 保证是从最后一层的叶子结点开始的
      Adjust(i);
    }
  }

  int GetIndex(int i = 0) const { return ls_[0]; }
  T& operator[](int i) { return leave_[i]; }
  const T& operator[](int i) const { return leave_[i]; }
  bool IsEmpty() const { return leave_[ls_[0]] == NoValue; }

  // NOTE:务必搞懂叶子结点和其他结点在虚拟树上的位置关系。
  void Adjust(int index) {
    int parent = (index + K) / 2;  // index + K 算叶子结点在树上的虚拟位置
    while (parent > 0) {           // parent == 1 停止。
      if (compare_(leave_[index], leave_[ls_[parent]]))
        std::swap(index, ls_[parent]);
      // index 指向胜者。
      parent /= 2;
    }
    ls_[0] = index;
    // ls_[0] 用来存放冠军节点。
  }

  T Top() const { return leave_[ls_[0]]; }
  void Pop(int value = NoValue) {
    leave_[ls_[0]] = value;
    Adjust(ls_[0]);
  }
};
#endif
