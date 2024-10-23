// 不推荐使用。
#ifndef LINKSTRING_HPP_
#define LINKSTRING_HPP_

#include "LinkList.hpp"
class LinkString : public LinkList<char> {
  using List = LinkList<char>;
  using Node = LinkNode<char>;

 public:
  using LinkList::LinkList;

  LinkString(const char* arr) {
    Node* cur = GetHead();
    for (int i = 0; arr[i] != '\0'; ++i) {
      cur = cur->CreateNext(arr[i]);
    }
  }

  LinkString GetSubStr(const size_t begin, const size_t end) {
    LinkString rtn;
    Node* cur1 = PrevNode(Begin(), begin);
    cur1 = cur1->next;
    Node* cur2 = rtn.GetHead();
    for (int i = 0; i < end - begin; ++i) {
      cur2 = cur2->CreateNext(cur1->data);
      cur1 = cur1->next;
    }
    return rtn;
  }

  using LinkList<char>::Insert;

  void Insert(LinkString str, const size_t index) {
    Node* cur = PrevNode(Begin(), index);
    if (index != 0 && cur == End() || cur == nullptr) return;
    for (auto i = str.Begin(); i != str.End(); i = i->next) {
      cur = cur->CreateNext(i->data);
    }
  }

  using LinkList<char>::Erase;
  void Erase(const size_t begin, const size_t end) {
    Node* start = PrevNode(Begin(), begin);
    Node* term = PrevNode(start, end - begin);
    Node* temp = start->SkipNext();
    while (temp != term) {
      delete temp;
      temp = start->SkipNext();
    }
    delete temp;
  }

  void Replace(const LinkString& str, const size_t index) {
    Node* cur = PrevNode(Begin(), index);
    cur = cur->next;
    for (auto i = str.Begin(); i != End() && cur != End(); i = i->next) {
      cur->data = i->data;
      cur = cur->next;
    }
  }

  ~LinkString() = default;
};

#endif
