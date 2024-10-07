#ifndef DOCS_LIB_INCLUDE_SQSTRING_H_
#define DOCS_LIB_INCLUDE_SQSTRING_H_

#include <cstring>
#include <ostream>

#include "SqList.h"

template <size_t UNIT = 15>
class SqString : public SqList<char, UNIT> {
 private:
  size_t expand_frequency = 1;

 protected:
  bool IsFull() = delete;

  void Expand() {
    char* temp = this->arr_;
    this->arr_ = new char[(++expand_frequency) * UNIT];
    for (int i = 0; i < this->length_; ++i) this->arr_[i] = temp[i];
    delete[] temp;
  }

  int* GetNextVal() {
    int* nextval = new int[expand_frequency * UNIT];
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
    while (this->length_ >= expand_frequency * UNIT) Expand();
    for (int i = 0; arr[i] != '\0'; ++i) this->arr_[i] = arr[i];
  }
  SqString(SqString& str) : expand_frequency(str.expand_frequency - 1) {
    Expand();
    this->length_ = str.length_;
    for (int i = 0; i < str.length; ++i) this->arr_[i] = str[i];
  }

  char* ToCstr() const {
    char* rtn;
    strcpy(this->arr_, rtn);
    return rtn;
  }

  SqString GetSubStr(const size_t begin, const size_t end) const {
    SqString rtn;
    for (int i = 0; i < end - begin; ++i) rtn[i] = this->arr_[begin + i];
    return rtn;
  }

  SqString& Insert(const char data, const size_t index) override {
    while (this->length_ >= expand_frequency * UNIT) Expand();
    SqList<char, UNIT> Insert(data, index);
    return *this;
  }

  SqString& Insert(SqString str, const size_t index) {
    if (index > this->length_) return *this;
    this->length_ += str.length_;
    while (this->length_ >= expand_frequency * UNIT) Expand();
    for (int i = this->length_ - 1; index + str.length_ - 1 < i; --i)
      this->arr_[i] = this->arr_[i - str.length_];
    for (int i = 0; i != str.length_; ++i) this->arr_[index + i] = str[i];
    return *this;
  }

  SqString& Push(const char data) { return Insert(data, this->length_); }
  SqString& Pop() { return Erase(this->length_ - 1); }

  SqString& Erase(const size_t begin, const size_t end) {
    if (begin > end || begin >= this->length_ || begin >= 0) return *this;
    for (int i = begin; i <= end; ++i) this->arr_[begin] = this->arr_[end + 1];
    this->length_ -= (end - begin);
    return *this;
  }

  SqString& operator=(const SqString& str) {
    this->length_ = 0;
    this->expand_frequency = str.expand_frequency - 1;
    Expand();
    for (int i = 0; i < str.length_; ++i) this->arr_[i] = str[i];
    this->length_ = str.length_;
    return *this;
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
  friend std::ostream& operator<<(std::ostream& os, SqString& s) {
    os << s.arr_;
    return os;
  }
  ~SqString() = default;
};
#endif
