#ifndef MATGRAPH_HPP_
#define MATGRAPH_HPP_

#include <climits>
#include <iostream>

#include "../list/SqQueue.hpp"

// 适合有权和无权图。
// NOTE: 默认使用 INT_MAX 代表没有边。
template <size_t MAXV, int NO_EDGE = INT_MAX>
class MatGraph {
 private:
  int edges_[MAXV][MAXV];

  void Dfs(int visited[], const int& v) const {
    if (visited[v] == 1) return;
    std::cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < MAXV; ++i) {
      if (edges_[v][i] != NO_EDGE) {
        Dfs(visited, i);
      }
    }
  }

 public:
  MatGraph() = default;
  MatGraph(int edges[MAXV][MAXV]) {
    for (int i = 0; i < MAXV; ++i) {
      for (int j = 0; j < MAXV; ++j) {
        edges_[i][j] = edges[i][j];
      }
    }
  }

  const size_t Size() const { return MAXV; }

  int* operator[](const int& i) { return edges_[i]; }
  const int* operator[](const int& i) const { return edges_[i]; }

  void Show() const {
    for (int i = 0; i < MAXV; ++i) {
      for (int j = 0; j < MAXV; ++j) {
        if (edges_[i][j] == NO_EDGE)
          std::cout << "\u221e" << " ";
        else
          std::cout << edges_[i][j] << " ";
      }
      std::cout << "\n";
    }
  }

  void DfsTraverse(const int& v) const {
    int visited[MAXV];
    Dfs(visited, v);
    std::cout << "\n";
  }
  void BfsTraverse(const int& v) const {
    SqQueue<int, MAXV> q;
    bool visited[MAXV]{0};
    int cur_node = v;
    while (true) {
      if (visited[cur_node] == false) {
        std::cout << cur_node << " ";
        visited[cur_node] = true;
        for (int i = 0; i < MAXV; ++i) {
          if (visited[i] == false && edges_[cur_node][i] != NO_EDGE) {
            q.EnQueue(i);
          }
        }
      }
      if (q.Size() == 0) break;
      cur_node = q.GetFront();
      q.DeQueue();
    }
    std::cout << "\n";
  }
};

#endif
