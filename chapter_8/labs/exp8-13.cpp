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
  int min = 0;
  for (int i = 1; i < MAXV; ++i) {
    if (close[i][i] > close[min][min]) min = i;
  }

  if (close[min][min] != INT_MAX) {
    cout << "最小环：";
    LinkStack<int> s{min};
    int i = min;
    do {
      i = path[min][i];
      s.Push(i);
    } while (i != min);
    cout << s << "\n长度：" << close[min][min] << "\n";
  } else {
    cout << "没有最小环！\n";
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
  Floyd(G);
}
