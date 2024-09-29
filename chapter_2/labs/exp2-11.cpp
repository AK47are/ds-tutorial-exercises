#include <string>
#include <iostream>
#include <fstream>

#include "../../docs/lib/include/LinkList.h"

using namespace std;

struct Worker{
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

int main() {
  LinkList<Worker> L;
  Worker temp;
  ifstream fin("emp.dat");
  while (fin.is_open()) {
    fin >> temp.no >> temp.name >> temp.depno >> temp.salary;
    L.Insert(temp, L.End());
  }
  cin >> temp.no >> temp.name >> temp.depno >> temp.salary;
  L.Insert(temp, L.End());
  cout << L;


}
