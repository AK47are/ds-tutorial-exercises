#include <climits>

#include "dependency.h"
using namespace std;

template <size_t MAXV>
void Dfs(const AdjGraph<MAXV>& g, bool visited[], const int& v,
         SqStack<int, MAXV>& path) {
  visited[v] = 1;
  path.Push(v);
  if (path.Size() == MAXV) cout << path << "\n";
  for (auto cur = g[v].Begin(); cur != g[v].End(); cur = cur->next) {
    if (visited[cur->data.index] == 0) Dfs(g, visited, cur->data.index, path);
  }
  visited[v] = 0;
  path.Pop();
}

int main() {
  int edges[5][5] = {{INT_MAX, 1, INT_MAX, 1, 1},
                     {1, INT_MAX, 1, 1, INT_MAX},
                     {INT_MAX, 1, INT_MAX, 1, 1},
                     {1, 1, 1, INT_MAX, 1},
                     {1, INT_MAX, 1, 1, INT_MAX}};
  AdjGraph g(edges);
  bool visited[5]{0};
  SqStack<int, 5> path;
  Dfs(g, visited, 0, path);
}
