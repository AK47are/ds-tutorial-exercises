// TODO: 自动生成迷宫，图形化迷宫界面
#include <iostream>

#include "dependence.h"
using namespace std;

struct Cursor {
  size_t x;
  size_t y;
  size_t di;

  bool operator==(const Cursor cur) { return (x == cur.x && y == cur.y); }
  Cursor LookLeft() const { return Cursor{x, y - 1}; }
  Cursor LookRight() const { return Cursor{x, y + 1}; }
  Cursor LookUp() const { return Cursor{x - 1, y}; }
  Cursor LookDown() const { return Cursor{x + 1, y}; }
  void MoveLeft() { --y, di = 0; }
  void MoveRight() { ++y, di = 0; }
  void MoveUp() { --x, di = 0; }
  void MoveDown() { ++x, di = 0; }
  friend ostream& operator<<(ostream& os, const Cursor& cur) {
    os << " <- (" << cur.x << ", " << cur.y << ", " << cur.di << ")";
    return os;
  }
};

template <size_t M, size_t N>
class Maze {
 private:
  int mg_[M][N];

 public:
  Cursor entrance_;
  Cursor exit_;
  Maze() {}  // TODO: 自动生成迷宫。
  Maze(int (*mg)[N], Cursor entrance, Cursor exit)
      : entrance_(entrance), exit_(exit) {
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j) mg_[i][j] = mg[i][j];
  }
  int& operator[](Cursor cur) { return mg_[cur.x][cur.y]; }
};

int main() {
  const unsigned Height = 9, Width = 15, MAX = 50;
  int a[Height][Width]{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                       {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                       {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                       {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                       {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                       {1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  Maze<Height, Width> mg{a, {1, 1, 0}, {Height - 2, Width - 2, 0}};
  // cout << mg[Cursor{5, 10}] << "\n";
  LinkStack<Cursor> path[MAX];
  for (int i = 0; i < MAX; ++i) path[i].Push(Cursor{0, 0, 4});
  Cursor cur = mg.entrance_;
  int i = 0;
  do {
    mg[cur] = -1;
    // cout << cur << path[i] << "\n";
    if (cur == mg.exit_) {
      path[i + 1] = path[i];
      path[i].Push(cur);
      mg[cur] = 0;
      ++i;
      cur = path[i].GetTop();
      path[i].Pop();
      continue;
    } else if (cur.di <= 0 && mg[cur.LookRight()] == 0) {
      cur.di = 1;
      path[i].Push(cur);
      cur.MoveRight();
    } else if (cur.di <= 1 && mg[cur.LookDown()] == 0) {
      cur.di = 2;
      path[i].Push(cur);
      cur.MoveDown();
    } else if (cur.di <= 2 && mg[cur.LookLeft()] == 0) {
      cur.di = 3;
      path[i].Push(cur);
      cur.MoveLeft();
    } else if (cur.di <= 3 && mg[cur.LookUp()] == 0) {
      cur.di = 4;
      path[i].Push(cur);
      cur.MoveUp();
    } else {
      mg[cur] = 0;
      cur = path[i].GetTop();
      path[i].Pop();
    }
  } while (!path[i].IsEmpty());
  if (path[0].IsEmpty()) {
    cout << "死路！\n";
  } else {
    cout << "全部路径: \n";
    for (int j = 0; j < i; ++j) cout << path[j] << "\n";
    cout << "最短路径为： \n";
    int min = 0;
    for (int j = 0; j < i; ++j)
      if (path[min].Size() > path[j].Size()) min = j;
    cout << path[min] << "\n";
  }
}
