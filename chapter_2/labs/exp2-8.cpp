#include <iostream>

#include "../../docs/include/LinkList.hpp"

template <typename T>
void UnionSet(LinkNode<T>* A, LinkNode<T>* B, LinkNode<T>* C) {
  auto c_rear = C;
  auto a_cur = A->next;
  auto b_cur = B->next;
  while (a_cur != nullptr && b_cur != nullptr) {
    if (a_cur->data < b_cur->data) {
      c_rear->CreateNext(a_cur->data);
      c_rear = c_rear->next;
      c_rear->data = a_cur->data;
      a_cur = a_cur->next;
    } else if (a_cur->data > b_cur->data) {
      c_rear->CreateNext(b_cur->data);
      c_rear = c_rear->next;
      b_cur = b_cur->next;
    } else {
      c_rear->CreateNext(b_cur->data);
      c_rear = c_rear->next;
      a_cur = a_cur->next, b_cur = b_cur->next;
    }
  }
  while (a_cur != nullptr) {
    c_rear->CreateNext(a_cur->data);
    c_rear = c_rear->next;
    a_cur = a_cur->next;
  }
  while (b_cur != nullptr) {
    c_rear->CreateNext(b_cur->data);
    c_rear = c_rear->next;
    b_cur = b_cur->next;
  }
}
template <typename T>
void Intersection(LinkNode<T>* A, LinkNode<T>* B, LinkNode<T>* C) {
  auto c_rear = C;
  auto a_cur = A->next;
  auto b_cur = B->next;
  while (a_cur && b_cur) {
    if (a_cur->data < b_cur->data) {
      a_cur = a_cur->next;
    } else if (a_cur->data > b_cur->data) {
      b_cur = b_cur->next;
    } else {
      c_rear->CreateNext(a_cur->data);
      c_rear = c_rear->next;
      a_cur = a_cur->next;
      b_cur = b_cur->next;
    }
  }
}

template <typename T>
void Difference(LinkNode<T>* A, LinkNode<T>* B, LinkNode<T>* C) {
  auto c_rear = C;
  auto a_cur = A->next;
  auto b_cur = B->next;
  while (a_cur && b_cur) {
    if (a_cur->data < b_cur->data) {
      c_rear->CreateNext(a_cur->data);
      c_rear = c_rear->next;
      a_cur = a_cur->next;
    } else if (a_cur->data > b_cur->data) {
      b_cur = b_cur->next;
    } else {
      a_cur = a_cur->next;
      b_cur = b_cur->next;
    }
  }
  while (a_cur) {
    c_rear->CreateNext(a_cur->data);
    c_rear = c_rear->next;
    a_cur = a_cur->next;
  }
}

int main() {
  LinkList<int> ha{1, 3, 4, 11, 12, 16}, hb{4, 7, 9, 11, 14, 16, 17};
  LinkList<int> hc;
  UnionSet(ha.GetHead(), hb.GetHead(), hc.GetHead());
  std::cout << hc << "\n";
  hc.GetHead()->next = hc.End();
  Intersection(ha.GetHead(), hb.GetHead(), hc.GetHead());
  std::cout << hc << "\n";
  hc.GetHead()->next = hc.End();
  Difference(ha.GetHead(), hb.GetHead(), hc.GetHead());
  std::cout << hc << "\n";
}
