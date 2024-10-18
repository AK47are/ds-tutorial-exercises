#ifndef DOCS_LIB_INCLUDE_DYNLIST_H_
#define DOCS_LIB_INCLUDE_DYNLIST_H_

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
      temp = new char[Capacity()];
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
  using List::SqList;
  const size_t Capacity() const { return (expand_frequency_ + 1) * UNIT; }

  void Insert(const T x, const size_t index) {
    List::Insert(x, index);
    AutoExpand();
  }

  T Erase(const size_t index) { return List::Erase(index); }
  ~DynList() = default;
};

#endif
