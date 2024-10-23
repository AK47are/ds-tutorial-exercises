#ifndef SQSTRING_HPP_
#define SQSTRING_HPP_

#include <cstring>

#include "DynList.hpp"

class SqString : public DynList<char, 15> {
 protected:
  int* GetNextval() const {  // NOTE:得到返回值用完记得 delete[]
    int* nextval = new int[this->Capacity()];
    nextval[0] = -1;
    int i = 0, j = -1;
    while (i < this->Size())
      if (j == -1 || this->GetArr()[j] == this->GetArr()[i]) {
        ++i, ++j;
        nextval[i] = (this->GetArr()[j] != this->GetArr()[i]) ? j : nextval[j];
      } else {
        j = nextval[j];
      }
    return nextval;
  }

 public:
  SqString() = default;
  SqString(const char* arr) {
    size_t length = this->Size();
    while (arr[length] != '\0') this->SetLength(++length);
    for (int i = 0; arr[i] != '\0'; ++i) this->GetArr()[i] = arr[i];
  }
  SqString(const SqString& str) {
    this->SetLength(str.Size());
    for (int i = 0; i < str.Size(); ++i) this->GetArr()[i] = str[i];
  }

  const char* GetCstr() {
    this->GetArr()[this->Size()] = '\0';
    return this->GetArr();
  }

  SqString GetSubStr(const size_t begin, const size_t end) const {
    SqString rtn;
    rtn.SetLength(end - begin);
    for (int i = 0; i < end - begin; ++i) {
      rtn.GetArr()[i] = this->GetArr()[begin + i];
    }
    return rtn;
  }

  using DynList<char, 15>::Insert;

  void Insert(SqString str, const size_t index) {
    if (index > this->Size()) return;  // *this;
    this->SetLength(this->Size() + str.Size());
    for (int i = this->Size() - 1; index + str.Size() - 1 < i; --i) {
      this->GetArr()[i] = this->GetArr()[i - str.Size()];
    }
    for (int i = 0; i != str.Size(); ++i) {
      this->GetArr()[index + i] = str[i];
    }
    // return *this;
  }

  SqString& Push(const SqString& str) {
    Insert(str, this->Size());
    return *this;
  }

  SqString& Push(const char data) {
    Insert(data, this->Size());
    return *this;
  }
  char Pop() { return Erase(this->Size() - 1); }

  using DynList<char, 15>::Erase;
  void Erase(const size_t begin, const size_t end) {
    if (begin >= end || end > this->Size()) return;  // *this;
    for (int i = 0; i < this->Size() - (end - 1); ++i) {
      this->GetArr()[begin + i] = this->GetArr()[end + i];
    }
    this->SetLength(this->Size() - (end - begin));
    // return *this;
  }

  void Replace(const SqString& str, const size_t index) {
    for (int i = 0; index + i < this->Size() && i < str.Size(); ++i) {
      this->GetArr()[index + i] = str[i];
    }
    // return *this;
  }

  // 查找第 num 个 str 子串下标。
  long Find(const SqString& str, const size_t num = 1) const {
    int* nextval = str.GetNextval();
    int i = 0, j = 0, n = 0, index = -1;
    while (i < this->Size() && n < num) {
      if (j == -1 || this->GetArr()[i] == str[j]) {
        ++i, j++;
      } else {
        j = nextval[j];
      }
      if (j == str.Size()) {
        index = i - j, ++n, j = 0, i = index + 1;
      }
    }
    delete[] nextval;
    if (n != num) return -1;
    return index;
  }

  SqString operator+(const SqString& str) {
    SqString rtn = *this;
    rtn.Push(str);
    return rtn;
  }

  SqString& operator=(const SqString& str) {
    this->SetLength(str.Size());
    for (int i = 0; i < str.Size(); ++i) {
      this->GetArr()[i] = str[i];
    }
    return *this;
  }

  bool operator==(const SqString& str) const {
    return (strcmp(this->GetArr(), str.GetArr()) == 0);
  }
  bool operator<(const SqString& str) const {
    return (strcmp(this->GetArr(), str.GetArr()) < 0);
  }
  bool operator>(const SqString& str) const {
    return (strcmp(this->GetArr(), str.GetArr()) > 0);
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
