#ifndef DOCS_LIB_INCLUDE_DYNLIST_H_
#define DOCS_LIB_INCLUDE_DYNLIST_H_

#include "SqList.hpp"

template <typename T, size_t UNIT = 15>
class DynList : public SqList<T, UNIT> {
  using List = SqList<T, UNIT>;

 private:
  size_t expand_frequency_ = 0;

  using List::GetLength;

 protected:
  bool IsFull() = delete;

  void AutoExpand() {  // 依靠 length_ 自动扩充
    if (this->GetLength() >= expand_frequency_ * UNIT) {
      T* temp;
      while (this->GetLength() >= expand_frequency_ * UNIT) {
        ++expand_frequency_;
        temp = new char[(expand_frequency_ + 2) * UNIT];
      }
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
  const size_t Capacity() const { return (expand_frequency_ + 1) * UNIT; }

  DynList& Insert(const T x, const size_t index) {
    List::Insert(x, index);
    AutoExpand();
    return *this;
  }

  DynList& Erase(const size_t index) {
    List::Erase(index);
    return *this;
  }

  ~DynList() = default;
};

#endif
