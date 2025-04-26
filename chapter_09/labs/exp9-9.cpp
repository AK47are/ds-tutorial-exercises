#include "dependency.h"

struct Data {
  char c;
  int count;
  bool operator<(const Data& d) { return c < d.c; }
  bool operator>(const Data& d) { return c > d.c; }
  bool operator==(const Data& d) { return c == d.c; }
  bool operator!=(const Data& d) { return c != d.c; }

  friend ostream& operator<<(ostream& os, const Data& d) {
    os << "<" << d.c << ", " << d.count << "> ";
    return os;
  }
};

int main() {
  BSTree<Data> t;
  SqString str;
  cin >> str;
  for (int i = 0; i < str.Size(); ++i) {
    BtNode<Data>* cur = t.Find(Data{str[i], 1});
    if (!cur)
      t.Insert(Data{str[i], 1});
    else
      ++cur->data.count;
  }
  t.Show(cout, t.GetRoot(), t.InOrder);
  cout << "\n";
}
