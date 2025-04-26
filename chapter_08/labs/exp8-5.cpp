#include <algorithm>
#include <numeric>
#define M INT_MAX
#include "dependency.h"

// O(V^2)
template <size_t MAXV>
void Prim(const AdjGraph<MAXV> G, const int& v) {
  bool visited[MAXV];
  fill(visited, visited + MAXV, 0);
  int close[MAXV];
  fill(close, close + MAXV, M);
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
      if (visited[cur->data.index] == 0 &&
          close[cur->data.index] > cur->data.weight) {
        path[cur->data.index] = min_index;
        close[cur->data.index] = cur->data.weight;
      }
    }
  }
  for (int i = 0; i < MAXV; ++i) cout << path[i] << " ";
  cout << "\n";
}

int main() {
  int arr[6][6] = {{M, 5, 8, 7, M, 3}, {5, M, 4, M, M, M}, {8, 4, M, 5, M, M},
                   {7, M, 5, 5, M, M}, {M, M, M, 5, M, 1}, {3, M, 9, M, 1, M}};
  AdjGraph G(arr);
  Prim(G, 0);
}
