#include <climits>
#include <iomanip>

#include "dependency.h"

template <size_t MAXV>
void Floyd(const MatGraph<MAXV>& G) {
  // 注意溢出。
  long close[MAXV][MAXV];
  int path[MAXV][MAXV];
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      close[i][j] = G[i][j];
      if (G[i][j] == INT_MAX) {
        path[i][j] = -1;
      } else {
        // 必须为 i ，初始化前驱结点。
        path[i][j] = i;
      }
    }
  }
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      for (int k = 0; k < MAXV; ++k) {
        if (close[j][i] + close[i][k] < close[j][k]) {
          close[j][k] = close[j][i] + close[i][k];
          path[j][k] = path[i][k];
        }
      }
    }
  }
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      if (close[i][j] == INT_MAX)
        cout << setw(2) << "\u221e" << " ";
      else
        cout << setw(2) << close[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      cout << path[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int edges[6][6] = {{INT_MAX, 5, INT_MAX, 7, INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX},
                     {8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9},
                     {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, 6},
                     {INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX},
                     {3, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX}};
  MatGraph G(edges);
  G.Show();
  cout << "\n";
  Floyd(G);
}
