#include <fstream>
#include <vector>

#include "dependency.h"

// 编号 1 代表数组下标 0 。
void Dijkstra(const int& s, const int& t, const vector<vector<int>>& matrix) {
  int N = matrix.size();
  int min = 0;
  bool visited[N];
  fill(visited, visited + N, 0);
  visited[s] = 1;
  long close[N];
  fill(close, close + N, INT_MAX);
  for (int i = 0; i < N; ++i) {
    if (matrix[s][i] != INT_MAX) close[i] = matrix[s][i];
  }
  while (true) {
    int min_index = -1;
    for (int i = 0; i < N; ++i) {
      if (visited[i] == 0 && close[i] != INT_MAX) {
        if (min_index == -1)
          min_index = i;
        else
          min_index = (close[i] < close[min_index]) ? i : min_index;
      }
    }
    if (min_index == -1) break;
    visited[min_index] = 1;
    for (int i = 0; i < N; ++i) {
      if (close[min_index] + matrix[min_index][i] < close[i])
        close[i] = close[min_index] + matrix[min_index][i];
    }
  }
  // for (int i = 0; i < N; ++i) cout << close[i] << " ";
  // cout << "\n";
  cout << close[t] << "\n";
}

int main() {
  fstream fin("data16.txt");
  int n, m;
  fin >> n >> m;
  vector<vector<int>> length(n, vector<int>(n, INT_MAX)),
      cost(n, vector<int>(n, INT_MAX));
  for (int i = 0; i < m; ++i) {
    int b, e, l, c;
    fin >> b >> e >> l >> c;
    length[b - 1][e - 1] = l;
    length[e - 1][b - 1] = l;
    cost[b - 1][e - 1] = c;
    cost[e - 1][b - 1] = c;
  }
  int s, t;
  fin >> s >> t;
  cout << "最短距离：";
  Dijkstra(s - 1, t - 1, length);
  cout << "最短花费：";
  Dijkstra(s - 1, t - 1, cost);
}
