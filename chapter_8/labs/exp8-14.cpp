#include <fstream>
#include <numeric>
#include <queue>
#include <vector>
#define M INT_MAX

#include "dependency.h"
int max_value = 0;

struct Edge {
  int begin;
  int end;
  int weight;
  bool operator<(const Edge& e) const { return weight < e.weight; }
  bool operator>(const Edge& e) const { return weight > e.weight; }
};

int Parent(const vector<int>& parent, int i) {
  if (i == parent[i]) return i;
  return Parent(parent, parent[i]);
}

int main() {
  priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
  fstream fin("data14.txt");
  int n, temp;
  fin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      fin >> temp;
      edges.push(Edge{i, j, temp});
      matrix[i][j] = temp;
      matrix[j][i] = temp;
    }
  }
  int q;
  fin >> q;
  vector<int> parent(n);
  iota(parent.begin(), parent.end(), 0);
  for (int i = 0; i < q; ++i) {
    int a, b;
    fin >> a >> b;
    parent[Parent(parent, b - 1)] = parent[Parent(parent, a - 1)];
  }
  while (!edges.empty()) {
    auto edge = edges.top();
    edges.pop();
    int i = Parent(parent, edge.begin);
    int j = Parent(parent, edge.end);
    if (i != j) {
      parent[j] = parent[i];
      max_value += matrix[edge.begin][edge.end];
    }
  }
  cout << max_value << "\n";
}
