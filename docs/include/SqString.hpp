#ifndef DOCS_LIB_INCLUDE_SQSTRING_H_
#define DOCS_LIB_INCLUDE_SQSTRING_H_

#include <cstring>

#include "SqList.h"

template <size_t UNIT = 15>
class SqString : public SqList<char, UNIT> {
 private:
  size_t expand_frequency_ = 0;

 protected:
  bool IsFull() = delete;

  void AutoExpand() {  // 依靠 length_ 自动扩充
    if (this->length_ >= expand_frequency_ * UNIT) {
      char* temp;
      while (this->length_ >= expand_frequency_ * UNIT) {
        ++expand_frequency_;
        temp = new char[(expand_frequency_ + 2) * UNIT];
      }
      for (int i = 0; i < this->length_; ++i) {
        temp[i] = this->arr_[i];
      }
      delete[] this->arr_;
      this->arr_ = temp;
    }
  }

  int* GetNextval() const {  // NOTE:得到返回值用完记得 delete[]
    int* nextval = new int[(expand_frequency_ + 1) * UNIT];
    nextval[0] = -1;
    int i = 0, j = -1;
    while (i < this->length_)
      if (j == -1 || this->arr_[j] == this->arr_[i]) {
        ++i, ++j;
        nextval[i] = (this->arr_[j] != this->arr_[i]) ? j : nextval[j];
      } else {
        j = nextval[j];
      }
    return nextval;
  }

 public:
  SqString() = default;
  SqString(const char* arr) {
    while (arr[this->length_] != '\0') ++this->length_;
    AutoExpand();
    for (int i = 0; arr[i] != '\0'; ++i) this->arr_[i] = arr[i];
  }
  SqString(SqString& str) {
    this->length_ = str.length_;
    AutoExpand();
    for (int i = 0; i < str.length_; ++i) this->arr_[i] = str[i];
  }

  const char* GetCstr() const {
    this->arr_[this->length_] = '\0';
    return this->arr_;
  }

  SqString GetSubStr(const size_t begin, const size_t end) const {
    SqString rtn;
    for (int i = 0; i < end - begin; ++i) rtn[i] = this->arr_[begin + i];
    return rtn;
  }

  virtual SqString& Insert(const char data, const size_t index) override {
    AutoExpand();
    SqList<char, UNIT>::Insert(data, index);
    return *this;
  }

  SqString& Insert(SqString str, const size_t index) {
    if (index > this->length_) return *this;
    this->length_ += str.length_;
    AutoExpand();
    for (int i = this->length_ - 1; index + str.length_ - 1 < i; --i) {
      this->arr_[i] = this->arr_[i - str.length_];
    }
    for (int i = 0; i != str.length_; ++i) {
      this->arr_[index + i] = str[i];
    }
    return *this;
  }

  SqString& Push(const char data) { return Insert(data, this->length_); }
  SqString& Push(const SqString& str) { return Insert(str, this->length_); }
  SqString& Pop() { return Erase(this->length_ - 1); }

  SqString& Erase(const size_t begin, const size_t end) {
    if (begin >= end || end > this->length_) return *this;
    for (int i = 0; i < this->length_ - (end - 1); ++i) {
      this->arr_[begin + i] = this->arr_[end + i];
    }
    this->length_ -= (end - begin);
    return *this;
  }

  SqString& Replace(const SqString& str, const size_t index) {
    for (int i = 0; index + i < this->length_ && i < str.Size(); ++i) {
      this->arr_[index + i] = str[i];
    }
    return *this;
  }

  long Find(const SqString& str) const {
    int* nextval = str.GetNextval();
    int i = 0, j = 0;
    while (i < this->Size() && j != str.Size()) {
      if (j == -1 || this->arr_[i] == str[j]) {
        ++i, j++;
      } else {
        j = nextval[j];
      }
    }
    delete[] nextval;
    if (j == str.Size()) return i - j;
    return -1;
  }

  SqString& operator=(const SqString& str) {
    this->length_ = str.length_;
    AutoExpand();
    for (int i = 0; i < str.length_; ++i) {
      this->arr_[i] = str[i];
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const SqString& s) {
    os << s.arr_;
    return os;
  }

  bool operator==(const SqString& str) const {
    return (strcmp(this->arr_, str.arr_) == 0);
  }
  bool operator<(const SqString& str) const {
    return (strcmp(this->arr_, str.arr_) < 0);
  }
  bool operator>(const SqString& str) const {
    return (strcmp(this->arr_, str.arr_) > 0);
  }
  bool operator<=(const SqString& str) const {
    return (*this == str || *this < str);
  }
  bool operator>=(const SqString& str) const {
    return (*this == str || *this > str);
  }

  ~SqString() = default;
};
#endif
