#include <initializer_list>
#include <iostream>
template <typename T>
class linklist {
 protected:
  struct LinkNode {
    T data;
    LinkNode* next = nullptr;
  };

  LinkNode link;

  void truncate() { link.next = nullptr; }
  LinkNode* end() {
    LinkNode* p = &link;
    while (p->next != nullptr) p = p->next;
    return p;
  }

 public:
  linklist(){};

  linklist(std::initializer_list<T> il) {
    LinkNode* p1 = &link;
    for (auto p = il.begin(); p != il.end(); ++p) {
      p1->next = new LinkNode{*p, nullptr};
      p1 = p1->next;
    }
  }

  linklist(linklist& l) {
    LinkNode* p1 = &link;
    LinkNode* p2 = l->next;
    while (p2) {
      p1->next = new LinkNode{p2->data, nullptr};
      p1 = p1->next;
      p2 = p2->next;
    }
  }

  bool empty() const { return (link.next == nullptr); }
  unsigned size() const {
    unsigned i = 0;
    for (auto p = link.next; p != nullptr; p = p->next) ++i;
    return i;
  }

  linklist& erase(const unsigned pos) {
    LinkNode* p = &link;
    for (int i = 0; i < pos; ++i) p = p->next;
    LinkNode* temp = p->next;
    p->next = temp->next;
    delete temp;
    return *this;
  }

  linklist& insert(const T t, const unsigned pos) {
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

  linklist& push_back(const T t) {
    LinkNode* rear = end();
    rear->next = new LinkNode{t, nullptr};
    return *this;
  }

  unsigned index_find(const T n) {
    int i = 0;
    for (auto p = link.next; p != nullptr; p = p->next) {
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

  friend std::ostream& operator<<(std::ostream& os, linklist& s) {
    for (auto p = s.link.next; p != nullptr; p = p->next) os << " " << p->data;
    return os;
  }

  linklist& merge(linklist& ha, linklist& hb) {  // TODO: 考虑优化。
    LinkNode* p1 = (hb.size() <= ha.size()) ? ha.link.next : hb.link.next;
    LinkNode* p2 = (hb.size() <= ha.size()) ? hb.link.next : ha.link.next;
    LinkNode* pc = &link;
    while (p2) {
      pc->next = p1;
      p1 = p1->next;
      pc = pc->next;
      pc->next = p2;
      p2 = p2->next;
      pc = pc->next;
    }
    while (p1) {
      pc->next = p1;
      pc = pc->next, p1 = p1->next;
    }
    ha.truncate(), hb.truncate();
    return *this;
  }

  ~linklist() {
    LinkNode* left = &link;
    LinkNode* right = left->next;
    while (right != nullptr) {
      left = right;
      right = right->next;
      delete left;
    }
  }
};