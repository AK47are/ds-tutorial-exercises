#include <fstream>
#include <iostream>
#include <string>

#include "../../docs/lib/include/LinkList.h"

using namespace std;

struct Worker {
  string no;
  string name;
  unsigned depno;
  unsigned salary;

  friend ostream& operator<<(ostream& os, Worker& worker) {
    os << worker.no << " " << worker.name << " " << worker.depno << " "
       << worker.salary << "\n";
    return os;
  }
};

void Sort(LinkList<Worker>& l,
          bool (*func)(LinkNode<Worker>* cur, LinkNode<Worker>* min)) {
  LinkNode<Worker>* k = l.PrevNode(-1);
  bool flag = 0;
  while (k->next != nullptr) {
    LinkNode<Worker>* min = k->next;
    for (LinkNode<Worker>* cur = k->next; cur != nullptr; cur = cur->next)
      min = (func(cur, min)) ? cur : min;
    l.PrevNode(min)->next = min->next;
    min->next = l.PrevNode(-1)->next;
    l.PrevNode(-1)->next = min;
    if (flag == 0) {
      k = min, flag = 1;
    }
  }
}
int main() {
  LinkList<Worker> L;
  Worker temp;
  ifstream fin("emp.dat");
  while (fin) {
    fin >> temp.no >> temp.name >> temp.depno >> temp.salary;
    L.Insert(temp, L.End());
  }
  cin >> temp.no >> temp.name >> temp.depno >> temp.salary;
  L.Insert(temp, L.End());
  cout << "读取职工记录：\n" << L << "\n\n";
  Sort(L, [](LinkNode<Worker>* cur, LinkNode<Worker>* min) {
    return cur->data.no > min->data.no;
  });
  cout << "按职工号递增排序：\n" << L << "\n\n";
  Sort(L, [](LinkNode<Worker>* cur, LinkNode<Worker>* min) {
    return cur->data.depno > min->data.depno;
  });
  cout << "按部门号递增排序：\n" << L << "\n\n";
  Sort(L, [](LinkNode<Worker>* cur, LinkNode<Worker>* min) {
    return cur->data.salary > min->data.salary;
  });
  cout << "按工资递增排序：\n" << L << "\n\n";
  string delete_no;
  cout << "指定删除职工号对应的职工记录：";
  cin >> delete_no;
  for (auto cur = L.Begin(); cur != nullptr; cur = cur->next)
    if (cur->data.no == delete_no) L.Erase(cur);
  cout << "已删除：\n" << L << "\n\n";
  ofstream fout("emp.dat");
  fout << L;
}
