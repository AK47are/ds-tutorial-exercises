#ifndef DYNLIST_HPP_
#define DYNLIST_HPP_

#include "SqList.hpp"

template <typename T, size_t UNIT = 15>
class DynList : public SqList<T, UNIT> {
  using List = SqList<T, UNIT>;

 private:
  size_t expand_frequency_ = 0;

  using List::Erase;
  using List::GetLength;
  using List::Insert;
  bool IsFull() = delete;

 protected:
  void AutoExpand() {  // 依靠 length_ 自动扩充
    if (this->GetLength() >= Capacity()) {
      T* temp;
      while (this->GetLength() >= Capacity()) {
        ++expand_frequency_;
      }
      temp = new T[Capacity()];
      for (int i = 0; i < this->GetLength(); ++i) {
        temp[i] = this->GetArr()[i];
      }
      delete[] this->GetArr();
      this->GetArr() = temp;
    }
  }

  void SetLength(const size_t length) {
    this->GetLength() = length;
    AutoExpand();
  }

 public:
  DynList() = default;
  DynList(const DynList& list) {
    SetLength(list.Size());
    for (int i = 0; i != this->Size(); ++i) {
      this->GetArr[i] = list[i];
    }
  }

  DynList(std::initializer_list<T> il) {
    SetLength(il.size());
    int pos = 0;
    for (auto cur = il.begin(); cur != il.end(); ++cur) {
      this->GetArr()[pos++] = *cur;
    }
  }

  DynList& operator=(const DynList& l) {
    this->Clear();
    SetLength(l.Size());
    if (this != &l) {
      for (int i = 0; i < l.Size(); ++i) {
        this->GetArr()[i] = l[i];
      }
    }
    return *this;
  }
  const size_t Capacity() const { return (expand_frequency_ + 1) * UNIT; }

  void Insert(const T x, const size_t index) {
    List::Insert(x, index);
    AutoExpand();
  }

  void Erase(const size_t index) { List::Erase(index); }
  ~DynList() = default;
};

#endif
