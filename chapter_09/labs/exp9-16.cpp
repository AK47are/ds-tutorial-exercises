#include <fstream>

#include "dependency.h"

int main() {
  LPTable<int, 1200> table;
  ifstream fin("op.txt");
  int a, b, i = 1;
  while (fin >> a >> b) {
    cout << a << " " << b << "\n";
    switch (a) {
      case 1:
        table[i++] = b;
        break;
      case 2:
        table.Delete(b);
        break;
      case 3:
        cout << table[b] << "\n";
        break;
    }
    table.Show();
  }
}
