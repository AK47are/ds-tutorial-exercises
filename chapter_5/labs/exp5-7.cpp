// NOTE:解决问题必须可以遍历全部元素，实际上栈并太适合解决这个问题。
#include <iostream>

#include "dependency.h"
using namespace std;
struct Item {
  unsigned x;
  unsigned y;
  friend ostream& operator<<(ostream& os, const Item& coord) {
    os << "(" << coord.x << ", " << coord.y << ") <-";
    return os;
  }
  unsigned LeftDiagonal() const { return y - x; }
  unsigned RightDiagonal() const { return y + x; }
};

bool IsAttack(LinkStack<Item> left, Item right) {
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

// 递归遍历模板，适用于得到全排列。
void SolveQueen(LinkStack<Item>& sol, Item temp, unsigned n, unsigned& sum) {
  if (sol.Size() == n + 1) {  // 排列到底的条件
    ++sum;
    // cout << "找到组合：" << sol << "\n";
    sol.Pop();
    return;
  }
  while (true) {  // 遍历全部选择。
    // 去除不符合条件的选择。
    while (IsAttack(sol, temp) && temp.y != n) ++temp.y;
    if (temp.y == n) {  // 遍历完全部条件。
      sol.Pop();
      return;
    } else {  // 继续遍历。
      sol.Push(temp);
      // cout << sol << "\n";
      // NOTE:下面的语句结束前会弹出 temp 。
      SolveQueen(sol, Item{temp.x + 1, 0}, n, sum);
    }
    ++temp.y;
  }
}

int main() {
  unsigned n, sum = 0;
  cout << "输入皇后个数：";
  cin >> n;
  Item temp{0, 0};
  LinkStack<Item> sol{Item{0, n}};
  SolveQueen(sol, temp, n, sum);
  cout << "一共有 " << sum << " 种解法\n";
}
