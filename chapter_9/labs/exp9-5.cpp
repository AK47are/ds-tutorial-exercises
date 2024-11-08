#include <array>

#include "dependency.h"

enum Status { EMPTY, OCCUPIED, DELETED };
template <typename T>
struct Unit {
  int key;
  T data;
  Status status = EMPTY;
};

template <typename T, size_t CAPACITY>
class HashTable {
  using U = Unit<T>;

 private:
  U table[CAPACITY];

 public:
  void Delete(const int& key) {
    U& cur = Search(key);
    cur.status = DELETED;
  }

  U& Search(const int& key) {
    int adr = key / CAPACITY;
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
    U& cur = Search(key);
    return cur.data;
  }

  void Show() const {
    for (int i = 0; i < CAPACITY; ++i) {
      cout << "(" << i << " : <" << table[i].status;
      if (table[i].status == OCCUPIED) {
        cout << ", " << table[i].key;
      }
      cout << ">) ";
    }
    cout << "\n";
  }
};

int main() {
  const int capacity = 13;
  HashTable<int, capacity> h;
  array arr = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
  for (int i = 0; i < arr.size(); ++i) {
    h[arr[i]] = i;
  }
  h.Show();
  cout << "查询 key = 29: " << h[29] << "\n";
  h.Delete(77);
  cout << "删除 77 :\n";
  h.Show();
  cout << "重插入 77 :\n";
  h[77] = 10;
  cout << "查询 key = 77: " << h[77] << "\n";
  h.Show();
}
