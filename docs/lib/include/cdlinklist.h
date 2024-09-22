#include <initializer_list>  // TODO: 将所有链表类封装成抽象类
#include <iostream>
template <typename T>
class cdlinklist {
 private:
  struct LinkNode {
    LinkNode* prior = nullptr;
    T data;
    LinkNode* next = nullptr;
  };
  LinkNode link;

  LinkNode* end() {
    LinkNode* p = &link;
    while (p->next != &link) p = p->next;
    return p;
  }

 public:
  cdlinklist() : link(nullptr, 0, &link){};

  cdlinklist(std::initializer_list<T> il) {
    LinkNode* p1 = &link;
    for (auto p = il.begin(); p != il.end(); ++p) {
      p1->next = new LinkNode{p1, *p, nullptr};
      p1 = p1->next;
    }
    p1->next = &link;
  }

  cdlinklist(cdlinklist& l) {
    LinkNode* p1 = &link;
    LinkNode* p2 = l->next;
    while (p2) {
      p1->next = new LinkNode{p1, p2->data, nullptr};
      p1 = p1->next;
      p2 = p2->next;
    }
    p1->next = &link;
  }

  bool empty() const { return (link.next == &link); }

  unsigned size() const {
    unsigned i = 0;
    for (auto p = link.next; p != &link; p = p->next) ++i;
    return i;
  }

  cdlinklist& erase(const unsigned pos) {
    LinkNode* p = &link;
    for (int i = 0; i <= pos; ++i) p = p->next;
    LinkNode* left = p->prior;
    LinkNode* right = p->next;
    delete p;
    left->next = right;
    right->prior = left;
    return *this;
  }

  cdlinklist& insert(const T t, const unsigned pos) {
    if (pos < size()) {
      LinkNode* p = &link;
      for (int i = 0; i < pos; ++i) p = p->next;
      LinkNode* left = p;
      LinkNode* right = p->next;
      p = new LinkNode{left, t, right};
      left->next = p;
      right->prior = p;
    } else if (pos == size()) {
      push_back(t);
    }
    return *this;
  }

  cdlinklist& push_back(const T t) {
    LinkNode* rear = end();
    rear->next = new LinkNode{rear, t, &link};
    return *this;
  }

  unsigned index_find(const T n) {
    int i = 0;
    for (auto p = link.next; p != &link; p = p->next) {
      if (p->data == n) return i;
      ++i;
    }
    std::cerr << "No find!" << "\n";
    return size();
  }

  T& operator[](const unsigned int& pos) {
    LinkNode* p = link.next;
    for (unsigned int i = 0; i < pos; ++i) p = p->next;
    return p->data;
  }

  friend std::ostream& operator<<(std::ostream& os, cdlinklist& s) {
    for (auto p = s.link.next; p != &s.link; p = p->next) os << " " << p->data;
    return os;
  }

  ~cdlinklist() {
    LinkNode* left = &link;
    LinkNode* right = left->next;
    while (right != &link) {
      left = right;
      right = right->next;
      delete left;
    }
  }
};
