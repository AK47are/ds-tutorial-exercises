#include <iostream>
#include <ostream>

#include "dependence.h"
struct Term {
  double coneffict;
  int exponent;

  Term operator+(Term& term) {
    return Term{coneffict + term.coneffict, exponent};
  }
  Term operator*(Term& term) {
    return Term{coneffict * term.coneffict, exponent * term.exponent};
  }
  bool operator<(Term& term) { return (exponent < term.exponent); }
  bool operator>(Term& term) { return (exponent > term.exponent); }
  bool operator==(Term& term) { return (exponent == term.exponent); }
  bool operator<=(Term& term) { return (exponent <= term.exponent); }
  bool operator>=(Term& term) { return (exponent >= term.exponent); }
  bool operator!=(Term& term) { return (exponent != term.exponent); }
  friend std::ostream& operator<<(std::ostream& os, const Term& term) {
    if (term.coneffict >= 0) os << "+";
    os << term.coneffict << "x^" << term.exponent;
    return os;
  }
};

void PloySort(LinkList<Term>& l) {
  LinkNode<Term>* k = l.GetHead();
  bool flag = 0;
  while (k->next != nullptr) {
    LinkNode<Term>* min = k->next;
    for (LinkNode<Term>* cur = k->next; cur != nullptr; cur = cur->next)
      min = (cur->data.exponent > min->data.exponent) ? min : cur;
    l.PrevNode(l.Begin(), min)->next = min->next;
    min->next = l.GetHead()->next;
    l.GetHead()->next = min;
    if (flag == 0) {
      k = min, flag = 1;
    }
  }
}

template <typename T>
void Multiple(LinkNode<T>* A, LinkNode<T>* B, LinkNode<T>* C) {
  auto c_cur = C;
  for (auto a_cur = A->next; a_cur != nullptr; a_cur = a_cur->next)
    for (auto b_cur = B->next; b_cur != nullptr; b_cur = b_cur->next) {
      c_cur = c_cur->CreateNext(a_cur->data * b_cur->data);
    }
}

int main() {
  LinkList<Term> la{{2, 3}, {3, 1}, {-2, 4}, {1, 7}, {2.3, 2}};
  PloySort(la);
  std::cout << la << "\n";
  LinkList<Term> lb{{3, 9}, {1, 2}, {-7, 6}, {4, 1}, {-1, 7}};
  PloySort(lb);
  std::cout << lb << "\n";
  LinkList<Term> lc;
  Multiple(la.GetHead(), lb.GetHead(), lc.GetHead());
  PloySort(lc);
  LinkNode<Term>* temp;
  for (auto cur = lc.Begin(); cur->next != nullptr; cur = cur->next)
    if (cur->data == cur->next->data) {
      cur->data.coneffict += cur->next->data.coneffict;
      temp = cur->SkipNext();
      delete temp;
    }
  std::cout << lc << "\n";
}
