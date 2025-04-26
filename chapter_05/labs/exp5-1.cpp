#include <cmath>
#include <iostream>

#include "dependency.h"
const int MAX = 50;
struct Post {
  char name;
  SqStack<int, MAX> s;
};

void Hanoi1(Post& x, Post& y, Post& z, int n) {
  if (n == 0) return;
  Hanoi1(x, z, y, n - 1);
  z.s.Push(x.s.GetTop());
  x.s.Pop();
  // std::cout << "(" << x.name << " -> " << z.name << ")\n";
  Hanoi1(y, x, z, n - 1);
}

// n 为偶将放到 z 柱，为奇放到 y 柱。
void Hanoi2(Post& x, Post& y, Post& z, int n) {
  Post* s[3] = {&x, &y, &z};
  int count = 0, before, after, before_prev;
  int end = pow(2, n - 1);
  auto move = [](Post* x, Post* z) {
    z->s.Push(x->s.GetTop());
    x->s.Pop();
    // std::cout << "(" << x->name << " -> " << z->name << ")\n";
  };
  while (++count) {
    before = (count - 1) % 3;
    after = (count) % 3;
    before_prev = (count + 1) % 3;
    move(s[before], s[after]);
    if (count == end) break;
    if (s[before_prev]->s.IsEmpty()) {
      move(s[before], s[before_prev]);
    } else if (s[before]->s.IsEmpty()) {
      move(s[before_prev], s[before]);
    } else {
      if (s[before_prev]->s.GetTop() > s[before]->s.GetTop())
        move(s[before], s[before_prev]);
      else
        move(s[before_prev], s[before]);
    }
  }
}
int main() {
  int n;
  std::cout << "输入高度：";
  std::cin >> n;
  Post x{'x'}, y{'y'}, z{'z'};
  for (int i = 0; i < n; ++i) x.s.Push(n - i);
  Hanoi1(x, y, z, n);
  std::cout << z.s << "\n";
  z.s.Clear();
  for (int i = 0; i < n; ++i) x.s.Push(n - i);
  // n 为偶将放到 z 柱，为奇放到 y 柱。
  if (n % 2 == 1)
    Hanoi2(x, z, y, n);
  else
    Hanoi2(x, y, z, n);
  std::cout << z.s << "\n";
}
