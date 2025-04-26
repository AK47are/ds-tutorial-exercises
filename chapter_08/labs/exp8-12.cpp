#include <fstream>
#include <vector>

#include "dependency.h"

int Query(const vector<vector<int>>& matrix, int b, int e) {
  bool visited[matrix.size()];
  fill(visited, visited + matrix.size(), 0);
  LinkQueue<int> q;
  visited[b] = 1;
  int cur = b, min = -1, new_num = 0, after_num = 0;
  while (true) {
    for (int i = 0; i < matrix.size(); ++i) {
      if (visited[i] == 0 && matrix[cur][i] != 0) {
        q.EnQueue(i);
        visited[i] = 1;
        ++after_num;
      }
    }
    // cout << q << "\n";
    // cout << new_num << " " << after_num << "\n";
    if (q.Size() == 0 || cur == e) break;
    cur = q.GetFront();
    visited[cur] = 1;
    q.DeQueue();
    --new_num;
    if (new_num <= 0) {
      new_num = after_num;
      ++min;
      after_num = 0;
    }
  }

  if (cur != e)
    return -1;
  else
    return min;
}

int main() {
  ifstream fin("test.txt");
  int n, m;
  fin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  int b, e;
  for (int i = 0; i < m; ++i) {
    fin >> b >> e;
    matrix[b][e] = 1;
    matrix[e][b] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  int query_num = 0;
  fin >> query_num;
  for (int i = 0; i < query_num; ++i) {
    fin >> b >> e;
    Query(matrix, b, e);
    cout << "动物 " << b << " 和动物 " << e << " 最少翻译："
         << Query(matrix, b, e) << "\n";
  }
}
