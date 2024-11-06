
#include <climits>
#include <iomanip>
#define M INT_MIN
#include "dependency.h"
template <size_t MAXV, int NO_EDGE>
void Floyd(const MatGraph<MAXV, NO_EDGE>& G) {
  // 注意溢出。
  int max = INT_MIN;
  long close[MAXV][MAXV];
  int path[MAXV][MAXV];
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      if (i == j)
        close[i][j] = 0;
      else
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
        if (close[j][i] + close[i][k] > close[j][k]) {
          close[j][k] = close[j][i] + close[i][k];
          path[j][k] = path[i][k];
          max = (close[j][k] > max) ? close[j][k] : max;
        }
      }
    }
  }
  for (int i = 0; i < MAXV; ++i) {
    for (int j = 0; j < MAXV; ++j) {
      if (close[i][j] < 0) close[i][j] = -1;
      cout << setw(2) << close[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < MAXV; ++i) {
    if (close[0][i] + close[i][8] == max && path[0][i] != i) {
      cout << "<" << char('A' + path[0][i]) << ", " << char('A' + i)
           << "> 是关键活动。\n";
      if (path[0][8] != i && path[i][8] == i && i != 8) {
        cout << "<" << char('A' + i) << ", " << char('A' + 8)
             << "> 是关键活动。\n";
      }
    }
  }
}

int main() {
  int edges[9][9] = {{M, 6, 4, 5, M, M, M, M, M}, {M, M, M, M, 1, M, M, M, M},
                     {M, M, M, M, 1, M, M, M, M}, {M, M, M, M, M, M, M, 2, M},
                     {M, M, M, M, M, 9, 7, M, M}, {M, M, M, M, M, M, M, M, 2},
                     {M, M, M, M, M, M, M, M, 4}, {M, M, M, M, M, M, M, M, 4},
                     {M, M, M, M, M, M, M, M, M}};
  MatGraph<9, M> G(edges);
  Floyd(G);
}
