#include <algorithm>

#include "dependency.h"
#define M INT_MAX

const int MAXV = 15;
int u = 0, v = 14;
int must[] = {3, 7, 9}, avoid[] = {1, 11};
int path[MAXV], top = 0;
void Dfs(const AdjGraph<MAXV>&, bool[], const int&);

int main() {
  int matrix[15][15] = {{M, 1, 1, 1, M, M, M, M, M, M, M, M, M, M, M},
                        {1, M, M, M, M, 1, M, M, M, M, M, M, M, M, M},
                        {1, M, M, M, M, M, 1, M, M, M, M, M, M, M, M},
                        {1, M, M, M, 1, M, M, M, M, M, M, M, M, M, M},
                        {M, M, M, 1, M, M, M, 1, M, M, M, M, M, M, M},
                        {M, 1, M, M, M, M, 1, M, M, 1, M, M, M, M, M},
                        {M, M, 1, M, M, 1, M, 1, M, M, 1, M, M, M, M},
                        {M, M, M, M, 1, M, 1, M, M, M, M, 1, M, M, M},
                        {M, M, M, M, M, M, M, M, M, 1, M, M, 1, M, M},
                        {M, M, M, M, M, 1, M, M, 1, M, 1, M, M, 1, M},
                        {M, M, M, M, M, M, 1, M, M, 1, M, 1, M, M, M},
                        {M, M, M, M, M, M, M, 1, M, M, 1, M, M, M, M},
                        {M, M, M, M, M, M, M, M, 1, M, M, M, M, M, 1},
                        {M, M, M, M, M, M, M, M, M, 1, M, M, M, M, 1},
                        {M, M, M, M, M, M, M, M, M, M, M, M, 1, 1, M}};
  AdjGraph<MAXV> G(matrix);
  bool visited[MAXV];
  fill(visited, visited + MAXV, 0);
  for (int i : avoid) visited[i] = 1;
  Dfs(G, visited, u);
}

void Output() {
  // cout << path[top - 1] << "\n";
  if (path[top - 1] == v) {
    int flag = 1;
    for (auto i : must) {
      // cout << "Find: " << (find(path, path + top, i) == path + top) << "\n";
      if (find(path, path + top, i) == path + top) flag = 0;
    }
    if (flag == 1) {
      cout << "path: \n";
      for (int i = 0; i < top; ++i) {
        cout << path[i] << " ";
      }
      cout << "\n";
    }
  }
}

void Dfs(const AdjGraph<MAXV>& g, bool visited[], const int& u) {
  visited[u] = 1;
  path[top++] = u;
  Output();
  for (auto cur = g[u].Begin(); cur != g[u].End(); cur = cur->next) {
    if (visited[cur->data.index] == 0) Dfs(g, visited, cur->data.index);
  }
  visited[u] = 0;
  --top;
}
