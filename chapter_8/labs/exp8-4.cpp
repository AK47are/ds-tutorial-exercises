#include "dependency.h"
#define M INT_MAX
using namespace std;

template <size_t MAXV>
void Dfs(const MatGraph<MAXV>& g, bool visited[], const int& v,
         const int& prev) {
  if (visited[v] == 1) return;
  if (v != prev) std::cout << "<" << prev << ", " << v << ">" << ", ";
  visited[v] = 1;
  for (int i = 0; i < MAXV; ++i) {
    if (g[v][i] != INT_MAX) {
      Dfs(g, visited, i, v);
    }
  }
}

template <size_t MAXV>
void Bfs(const MatGraph<MAXV> g, const int& v) {
  SqQueue<int, MAXV> q, prev{v};
  bool visited[MAXV]{0};
  int cur_node = v;
  while (true) {
    if (visited[cur_node] == false) {
      if (prev.GetFront() != cur_node)
        std::cout << "<" << prev.GetFront() << ", " << cur_node << ">" << ", ";
      visited[cur_node] = true;
      for (int i = 0; i < MAXV; ++i) {
        if (visited[i] == false && g[cur_node][i] != INT_MAX) {
          q.EnQueue(i);
          prev.EnQueue(cur_node);
        }
      }
    }
    if (q.Size() == 0) break;
    cur_node = q.GetFront();
    q.DeQueue();
    prev.DeQueue();
  }
  std::cout << "\n";
}

int main() {
  int matrix[11][11] = {
      {M, 1, 1, 1, M, M, M, M, M, M, M}, {1, M, M, M, 1, 1, M, M, M, M, M},
      {1, M, M, 1, M, 1, 1, M, M, M, M}, {1, M, 1, M, M, M, M, 1, M, M, M},
      {M, 1, M, M, M, M, M, M, M, M, M}, {M, M, 1, M, M, M, M, M, M, M, M},
      {M, M, 1, M, M, M, M, 1, 1, 1, M}, {M, M, M, 1, M, M, M, M, M, M, 1},
      {M, M, M, M, M, M, 1, M, M, M, M}, {M, M, M, M, M, M, 1, M, M, M, M},
      {M, M, M, M, M, M, M, 1, M, M, M}};
  MatGraph g(matrix);
  g.Show();
  bool visited[11]{0};
  cout << "\n";
  Dfs(g, visited, 3, 3);
  cout << "\n\n";
  Bfs(g, 3);
}
