#include <functional>
#include <numeric>
#include <queue>
#include <vector>
#define M INT_MAX
#include "dependency.h"

struct Edge {
  int begin;
  int end;
  int weight;
  bool operator<(const Edge& e) const { return weight < e.weight; }
  bool operator>(const Edge& e) const { return weight > e.weight; }
};

// 并查集返回集合代表
int Parent(const int parent[], int i) {
  if (i == parent[i]) return i;
  return Parent(parent, parent[i]);
}

template <size_t MAXV>
void Kruskal(const MatGraph<MAXV>& G) {
  int parent[MAXV];
  iota(parent, parent + MAXV, 0);

  priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
  for (int i = 0; i < MAXV; ++i) {
    for (int j = i; j < MAXV; ++j) {
      if (G[i][j] != M) edges.push(Edge{i, j, G[i][j]});
    }
  }

  while (!edges.empty()) {
    auto edge = edges.top();
    edges.pop();
    int i = Parent(parent, edge.begin);
    int j = Parent(parent, edge.end);
    if (i != j) {
      parent[j] = parent[i];
      cout << "<" << edge.begin << ", " << edge.end << "> ";
    }
  }
  cout << "\n";
}

int main() {
  int arr[6][6] = {{M, 5, 8, 7, M, 3}, {5, M, 4, M, M, M}, {8, 4, M, 5, M, M},
                   {7, M, 5, 5, M, M}, {M, M, M, 5, M, 1}, {3, M, 9, M, 1, M}};
  MatGraph G(arr);
  Kruskal(G);
}
