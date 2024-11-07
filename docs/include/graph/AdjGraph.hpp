#ifndef ADJGRAPH_HPP_
#define ADJGRAPH_HPP_
#include <climits>
#include <iostream>

#include "../link/LinkList.hpp"

struct AdjData {
  int index;
  int weight;
};

template <size_t MAXV, int NO_EDGE = INT_MAX>
class AdjGraph {
  using List = LinkList<AdjData>;

 private:
  List vertex_[MAXV];

 public:
  AdjGraph() = default;
  AdjGraph(int edges[MAXV][MAXV]) {
    for (int i = 0; i < MAXV; ++i) {
      for (int j = 0; j < MAXV; ++j) {
        if (edges[i][j] != NO_EDGE)
          vertex_[i].Insert(AdjData{j, edges[i][j]}, vertex_[i].Size());
      }
    }
  }

  List& operator[](int i) { return vertex_[i]; }
  const List& operator[](int i) const { return vertex_[i]; }

  void Show() const {
    for (int i = 0; i < MAXV; ++i) {
      std::cout << "G[" << i << "] = ";
      for (auto cur = vertex_[i].Begin(); cur != vertex_[i].End();
           cur = cur->next) {
        std::cout << "(" << cur->data.index << ": " << cur->data.weight << ") ";
      }
      std::cout << "\n";
    }
  }
};

#endif
