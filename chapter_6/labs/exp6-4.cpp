#include <iostream>

const int M = 3, N = 3;
bool IsSaddlePoint(const int a[M][N], int x, int y) {
  for (int i = 0; i < M; ++i) {
    if (a[x][y] > a[x][i]) return false;
  }
  for (int j = 0; j < N; ++j) {
    if (a[x][y] < a[j][y]) return false;
  }
  return true;
}

using namespace std;
int main() {
  int A[3][3] = {{3, 1, 7}, {6, 5, 9}, {4, 3, 12}};
  cout << "马鞍点有：\n";
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (IsSaddlePoint(A, i, j)) cout << " A[" << i << "][" << j << "] ";
    }
  }
  cout << "\n";
}
