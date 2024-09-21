#include <iostream>
template <typename T>
class linklist {
 private:
  struct LinkNode {
    T data;
    linklist* next = nullptr;
  };
  LinkNode link;
  unsigned int length = 0;
  LinkNode* rear = this;

 public:
  linklist(){};

  linklist(linklist& l) : length(l.length) {
    LinkNode* p1 = link;
    LinkNode* p2 = l->next;
    while (p2) {
      p1->next = new LinkNode{p2->data, nullptr};
      p1 = p1->next;
      p2 = p2->next;
    }
    rear = p1;
  }

  bool empty() const { return (length == 0); }
  unsigned int size() const { return length; }

  linklist& insert(T& t, unsigned int pos) {
    if (pos > length) {
      std::cerr << "Over bound!\n";
      return *this;
    } else {
      for (int i = 0; i < pos; ++i) {
        // TODO:
      }
    }
    return *this;
  }

  linklist& push_back(T& t) {
    rear->next = new LinkNode{t, nullptr};
    rear = rear->next;
    ++length;
    return *this;
  }

  ~linklist() {
    if (!link->next) return;
    LinkNode* left = link->next;
    LinkNode* right = left->next;
    while (left != nullptr) {
      delete left;
      left = right;
      right = left->next;
    }
  }
};
