#include <initializer_list>
#include <iostream>
template <typename T>
class clinklist {
 private:
  struct LinkNode {
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
  clinklist() : link(0, &link){};

  clinklist(std::initializer_list<T> il) {
    LinkNode* p1 = &link;
    for (auto p = il.begin(); p != il.end(); ++p) {
      p1->next = new LinkNode{*p, nullptr};
      p1 = p1->next;
    }
    p1->next = &link;
  }

  clinklist(clinklist& l) {
    LinkNode* p1 = &link;
    LinkNode* p2 = l->next;
    while (p2) {
      p1->next = new LinkNode{p2->data, nullptr};
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

  clinklist& erase(const unsigned pos) {
    LinkNode* p = &link;
    for (int i = 0; i < pos; ++i) p = p->next;
    LinkNode* temp = p->next;
    p->next = temp->next;
    delete temp;
    return *this;
  }

  clinklist& insert(const T t, const unsigned pos) {
    if (pos < size()) {
      LinkNode* p = &link;
      for (int i = 0; i < pos; ++i) p = p->next;
      LinkNode* temp = p->next;
      p->next = new LinkNode{t, temp};
    } else if (pos == size()) {
      push_back(t);
    }
    return *this;
  }

  clinklist& push_back(const T t) {
    LinkNode* rear = end();
    rear->next = new LinkNode{t, &link};
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

  friend std::ostream& operator<<(std::ostream& os, clinklist& s) {
    for (auto p = s.link.next; p != &s.link; p = p->next) os << " " << p->data;
    return os;
  }

  ~clinklist() {
    LinkNode* left = &link;
    LinkNode* right = left->next;
    while (right != &link) {
      left = right;
      right = right->next;
      delete left;
    }
  }
};
