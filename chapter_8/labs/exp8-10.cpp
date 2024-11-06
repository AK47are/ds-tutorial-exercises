#include <numeric>

#include "dependency.h"
#define M INT_MAX

template <size_t MAXV>
void Dijkstra(const AdjGraph<MAXV>, int[], const int&);

template <size_t MAXV>
void Dfs(const MatGraph<MAXV>, int[], SqStack<int, MAXV>&, const int&,
         const int&, const int&);

int main() {
  int arr[6][6] = {{M, 1, M, 1, M, M}, {M, M, 1, M, M, M}, {1, M, M, M, M, 1},
                   {M, M, 1, M, M, 1}, {M, M, M, 1, M, M}, {1, 1, M, 1, 1, M}};
  MatGraph g(arr);
  int visited[6];
  SqStack<int, 6> path;
  cout << "顶点 5 到顶点 2 的全部路径：\n";
  Dfs(g, visited, path, 5, 2, 0);
  cout << "顶点 5 到顶点 2 长度为 3 的全部路径：\n";
  Dfs(g, visited, path, 5, 2, 3);
  cout << "从顶点 5 到顶点 2 的最短路径：\n";
  int path_arr[6], i = 2, prev = 0;
  AdjGraph G(arr);
  LinkStack<int> temp;
  Dijkstra(G, path_arr, 5);
  while (i != prev) {
    temp.Push(i);
    prev = i;
    i = path_arr[i];
  }
  cout << temp << "\n";
}

template <size_t MAXV>
void Dfs(const MatGraph<MAXV> g, int visited[MAXV], SqStack<int, MAXV>& path,
         const int& v, const int& e, const int& length) {
  if (visited[v] == 1) return;
  path.Push(v);
  if (v == e && (length == 0 || path.Size() - 1 == length))
    cout << path << "\n";
  visited[v] = 1;
  for (int i = 0; i < MAXV; ++i) {
    if (g[v][i] != M) {
      Dfs(g, visited, path, i, e, length);
    }
  }
  path.Pop();
  visited[v] = 0;
}

template <size_t MAXV>
void Dijkstra(const AdjGraph<MAXV> G, int path[MAXV], const int& v) {
  bool visited[MAXV];
  fill(visited, visited + MAXV, 0);
  int close[MAXV];
  fill(close, close + MAXV, INT_MAX);
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
}
