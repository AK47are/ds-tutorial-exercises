#ifndef LPTABLE_HPP_
#define LPTABLE_HPP_

#include <cstddef>
#include <iostream>

#include "HashNode.hpp"
// 采用线性探测法的哈希表，暂不支持自动扩容，很简陋。
template <typename T, size_t CAPACITY>
class LPTable {
  using Node = LPNode<T>;

 private:
  Node table[CAPACITY];

 public:
  void Delete(const int& key) {
    Node& cur = Search(key);
    cur.status = DELETED;
  }

  // 乘法哈希
  int Hash(const int& key) {
    const double A = 0.6180339887;  // 黄金分割常数的倒数
    double frac = key * A - int(key * A);
    return int(CAPACITY * frac);
  }

  Node& Search(const int& key) {
    int adr = Hash(key);
    int first_deleted = -1;
    while (table[adr].status != EMPTY) {
      if (table[adr].status == OCCUPIED && table[adr].key == key) break;
      if (first_deleted == -1 && table[adr].status == DELETED)
        first_deleted = adr;
      adr = (adr + 1) % CAPACITY;
    }
    if (table[adr].key != key)
      if (first_deleted != -1) adr = first_deleted;
    table[adr].key = key;
    table[adr].status = OCCUPIED;
    return table[adr];
  }

  int& operator[](const int& key) {
    Node& cur = Search(key);
    return cur.data;
  }

  void Show() const {
    for (int i = 0; i < CAPACITY; ++i) {
      if (table[i].status == OCCUPIED) {
        std::cout << "<" << table[i].key << ", " << table[i].data;
        std::cout << "> ";
      }
    }
    std::cout << "\n";
  }
};

#endif
