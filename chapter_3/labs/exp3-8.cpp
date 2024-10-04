#include <iostream>
#include <string>

#include "../../docs/lib/include/LinkStack.h"
using namespace std;
struct Coord {
  int x;
  int y;
  int di;
  bool operator==(Coord& coord) { return (x == coord.x && y == coord.y); }
  bool operator!=(Coord& coord) { return operator==(coord); }
  unsigned LeftDiagonal() { return y - x; }
  unsigned RightDiagonal() { return y + x; }
};

bool IsAttack(Coord left, Coord right) {
  if (left != right && left.LeftDiagonal() != right.LeftDiagonal() &&
      left.LeftDiagonal() != right.RightDiagonal())
    return false;
  else
    return true;
}

int main() {
  int n;
  cout << "输入皇后个数：";
  cin >> n;
  LinkStack<Coord> sol{Coord{0, 0, -1}};
  string status;
  Coord temp{0, 0, 0};
  while (!sol.IsEmpty()) {
    for (int i = 0; i < n; ++i)
      if (!IsAttack(sol.GetTop(), temp)) }
}
