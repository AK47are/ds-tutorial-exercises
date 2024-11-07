#include <climits>
#include <fstream>
#include <vector>

#include "dependency.h"

int main() {
  fstream fin("data15.txt");
  int N, M;
  fin >> N >> M;
  vector<vector<int>> matrix(N, vector<int>(N, INT_MAX));
  while (M--) {
    int start, target, price;
    fin >> start >> target >> price;
    matrix[start - 1][target - 1] = price;
  }

  // 编号 1 代表数组的 0 中。
  int min = 0;
  bool visited[N];
  fill(visited, visited + N, 0);
  visited[0] = 1;
  long close[N];
  fill(close, close + N, INT_MAX);
  for (int i = 0; i < N; ++i) {
    if (matrix[i][0] != INT_MAX) close[i] = matrix[i][0];
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
    min += close[min_index];
    visited[min_index] = 1;
    for (int i = 0; i < N; ++i) {
      if (close[min_index] + matrix[i][min_index] < close[i])
        close[i] = close[min_index] + matrix[i][min_index];
    }
  }
  cout << min << "\n";
}
