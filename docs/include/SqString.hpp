#ifndef DOCS_LIB_INCLUDE_SQSTRING_H_
#define DOCS_LIB_INCLUDE_SQSTRING_H_

#include <cstring>

#include "DynList.hpp"

template <size_t UNIT = 15>
class SqString : public DynList<char, UNIT> {
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
  SqString(SqString& str) {
    this->SetLength(str.Size());
    for (int i = 0; i < str.Size(); ++i) this->GetArr()[i] = str[i];
  }

  const char* GetCstr() const {
    this->GetArr()[this->Size()] = '\0';
    return this->GetArr();
  }

  SqString GetSubStr(const size_t begin, const size_t end) const {
    SqString rtn;
    for (int i = 0; i < end - begin; ++i) rtn[i] = this->GetArr()[begin + i];
    return rtn;
  }

  SqString& Insert(const char data, const size_t index) {
    SqList<char, UNIT>::Insert(data, index);
    return *this;
  }

  SqString& Insert(SqString str, const size_t index) {
    if (index > this->Size()) return *this;
    this->SetLength(this->Size() + str.Size());
    for (int i = this->Size() - 1; index + str.Size() - 1 < i; --i) {
      this->GetArr()[i] = this->GetArr()[i - str.Size()];
    }
    for (int i = 0; i != str.Size(); ++i) {
      this->GetArr()[index + i] = str[i];
    }
    return *this;
  }

  SqString& Push(const char data) { return Insert(data, this->Size()); }
  SqString& Push(const SqString& str) { return Insert(str, this->Size()); }
  SqString& Pop() { return Erase(this->Size() - 1); }

  SqString& Erase(const size_t begin, const size_t end) {
    if (begin >= end || end > this->Size()) return *this;
    for (int i = 0; i < this->Size() - (end - 1); ++i) {
      this->GetArr()[begin + i] = this->GetArr()[end + i];
    }
    this->SetLength(this->Size() - (end - begin));
    return *this;
  }

  SqString& Replace(const SqString& str, const size_t index) {
    for (int i = 0; index + i < this->Size() && i < str.Size(); ++i) {
      this->GetArr()[index + i] = str[i];
    }
    return *this;
  }

  long Find(const SqString& str) const {
    int* nextval = str.GetNextval();
    int i = 0, j = 0;
    while (i < this->Size() && j != str.Size()) {
      if (j == -1 || this->GetArr()[i] == str[j]) {
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
