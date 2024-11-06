#include <algorithm>
#include <climits>
#include <numeric>

#include "dependency.h"

// O(V^2)
template <size_t MAXV>
void Dijkstra(const AdjGraph<MAXV> G, const int& v) {
  bool visited[MAXV];
  fill(visited, visited + MAXV, 0);
  int close[MAXV];
  fill(close, close + MAXV, INT_MAX);
  int path[MAXV];
  iota(path, path + MAXV, 0);

  // 初始化
  visited[v] = 1;
  close[v] = 0;
  for (auto cur = G[v].Begin(); cur != G[v].End(); cur = cur->next) {
    path[cur->data.index] = v;
    close[cur->data.index] = cur->data.weight;
  }

  while (true) {
    int min_index = -1;
    for (int i = 0; i < MAXV; ++i) {
      if (visited[i] == 0) {
        if (min_index == -1)
          min_index = i;
        else
          min_index = (close[i] < close[min_index]) ? i : min_index;
      }
    }
    if (min_index == -1) break;
    visited[min_index] = 1;
    for (auto cur = G[min_index].Begin(); cur != G[min_index].End();
         cur = cur->next) {
      if (close[cur->data.index] > close[min_index] + cur->data.weight) {
        path[cur->data.index] = min_index;
        close[cur->data.index] = cur->data.weight + close[min_index];
      }
    }
  }
  for (int i = 0; i < MAXV; ++i) cout << path[i] << " ";
  cout << "\n";
  for (int i = 0; i < MAXV; ++i) cout << close[i] << " ";
  cout << "\n";
}

int main() {
  int edges[6][6] = {{INT_MAX, 5, INT_MAX, 7, INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX},
                     {8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9},
                     {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, 6},
                     {INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
                     {3, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX}};
  AdjGraph G(edges);
  Dijkstra(G, 0);
}
