#include <cctype>
#include <iostream>

#include "../../docs/lib/include/LinkList.h"

void Add(LinkNode<char>* a_cur, LinkNode<char>* b_cur, LinkList<char>& sum) {
  int carry = 0;
  while (a_cur || b_cur) {
    int a_val = (a_cur ? a_cur->data - '0' : 0);
    int b_val = (b_cur ? b_cur->data - '0' : 0);
    int total = a_val + b_val + carry;
    sum.Insert(total % 10 + '0', sum.Begin());
    carry = total / 10;
    if (a_cur) a_cur = a_cur->next;
    if (b_cur) b_cur = b_cur->next;
  }
  if (carry != 0) sum.Insert(carry + '0', sum.Begin());
}

using namespace std;
int main() {
  LinkList<char> la, lb, lc;
  cout << "输入任意整数：";
  while (isdigit(cin.peek())) la.Insert(cin.get(), la.Begin());
  cin.ignore();
  cout << "输入任意整数：";
  while (isdigit(cin.peek())) lb.Insert(cin.get(), lb.Begin());
  cin.ignore();
  Add(la.Begin(), lb.Begin(), lc);
  cout << la << "\n";
  cout << lb << "\n";
  cout << lc << "\n";
  auto slow = lc.Begin();
  auto fast = lc.Begin();
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  cout << "中间位为：" << slow->data << "\n";
}
