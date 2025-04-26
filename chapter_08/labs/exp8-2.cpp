#include <climits>

#include "dependency.h"

template <size_t MAXV>
void NonRecDfs(const MatGraph<MAXV>& g, const int& v) {
  SqStack<int, MAXV> s;
  bool visited[MAXV];
  int cur_node = v;
  while (true) {
    int cur = 0;
    if (visited[cur_node] != 1) {
      cout << cur_node << " ";
      while (cur != MAXV && (cur == cur_node || g[cur_node][cur] == INT_MAX ||
                             visited[cur] == 1))
        ++cur;
    }
    if (cur != MAXV && visited[cur_node] == 0) {
      visited[cur_node] = true;
      s.Push(cur_node);
      cur_node = cur;
    } else {
      cur_node = s.GetTop();
      s.Pop();
      if (s.Size() == 0) break;
    }
  }
  cout << "\n";
}

int main() {
  int edges[6][6] = {{INT_MAX, 5, INT_MAX, 7, INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX},
                     {8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9},
                     {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, 6},
                     {INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
                     {3, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX}};
  MatGraph g(edges);
  g.Show();
  cout << "\n";
  g.DfsTraverse(0);
  cout << "\n";
  NonRecDfs(g, 0);
  cout << "\n";
  g.BfsTraverse(0);
}
