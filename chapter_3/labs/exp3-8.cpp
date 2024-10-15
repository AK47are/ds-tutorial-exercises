// NOTE:解决问题必须可以遍历全部元素，实际上栈并太适合解决这个问题。
#include <iostream>
#include <string>

#include "../../docs/include/LinkStack.hpp"
using namespace std;
struct Coord {
  unsigned x;
  unsigned y;
  friend ostream& operator<<(ostream& os, Coord& coord) {
    os << "(" << coord.x << ", " << coord.y << ") <-";
    return os;
  }
  unsigned LeftDiagonal() const { return y - x; }
  unsigned RightDiagonal() const { return y + x; }
};

bool IsAttack(LinkStack<Coord> left, Coord right) {
  // cout << "left: " << left << "\t\t" << "\n";
  while (left.Size() != 1) {
    if (left.GetTop().y == right.y ||
        left.GetTop().LeftDiagonal() == right.LeftDiagonal() ||
        left.GetTop().RightDiagonal() == right.RightDiagonal())
      return true;
    left.Pop();
  }
  return false;
}

int main() {
  unsigned n, sum = 0;
  cout << "输入皇后个数：";
  cin >> n;
  LinkStack<Coord> sol{Coord{0, n}};
  string status;
  Coord temp{0, 0};
  while (!sol.IsEmpty()) {
    if (sol.Size() == n + 1) {
      ++sum;
      // cout << "找到组合：" << sol << "\n";
      temp = sol.GetTop();
      ++temp.y;
      sol.Pop();
    }
    // cout << sol << "\t\t" << "\n";
    while (IsAttack(sol, temp) && temp.y != n) ++temp.y;
    if (temp.y == n) {
      while (sol.GetTop().y == n - 1) sol.Pop();
      temp = sol.GetTop();
      ++temp.y;
      sol.Pop();
    } else {
      sol.Push(temp);
      ++temp.x, temp.y = 0;
    }
  }
  cout << "一共有 " << sum << " 种解法\n";
}
