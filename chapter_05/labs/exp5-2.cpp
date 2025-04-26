#include <iostream>

#include "dependency.h"

using namespace std;
struct Cursor {
  size_t x;
  size_t y;

  bool operator==(const Cursor cur) const { return (x == cur.x && y == cur.y); }
  Cursor LookRight() const { return Cursor{x, y + 1}; }
  Cursor LookDown() const { return Cursor{x + 1, y}; }
  friend ostream& operator<<(ostream& os, const Cursor& cur) {
    os << "(" << cur.x << ", " << cur.y << ") -> ";
    return os;
  }
};

void Path(const Cursor& cur, const Cursor exit, SqStack<Cursor, 30>& s) {
  if (cur.x > exit.x || cur.y > exit.y) return;
  if (cur == exit) {
    cout << s << "(" << cur.x << ", " << cur.y << ")\n";
  }
  s.Push(cur);
  Path(cur.LookRight(), exit, s);
  Path(cur.LookDown(), exit, s);
  s.Pop();
}

int main() {
  const unsigned m = 2, n = 2, MAX = 30;
  SqStack<Cursor, 30> s;
  Path(Cursor{0, 0}, Cursor{m - 1, n - 1}, s);
}
