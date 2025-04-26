#include <iostream>

using namespace std;
template <int MAX>
void Show(int a[MAX][MAX], int m = MAX) {
  if (m <= (MAX - 1) / 2 + 1) {
    if (MAX % 2 == 1) cout << " " << a[MAX / 2][MAX / 2];
    cout << "\n";
    return;
  }
  for (int i = MAX - m; i < m; ++i) cout << " " << a[MAX - m][i];
  for (int i = MAX - m + 1; i < m; ++i) cout << " " << a[i][m - 1];
  for (int i = m - 2; MAX - m <= i; --i) cout << " " << a[m - 1][i];
  for (int i = m - 2; MAX - m < i; --i) cout << " " << a[i][MAX - m];
  cout << "\n";
  Show(a, m - 1);
}

int main() {
  int spiral[9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                      {32, 33, 34, 35, 36, 37, 38, 39, 10},
                      {31, 56, 57, 58, 59, 60, 61, 40, 11},
                      {30, 55, 72, 73, 74, 75, 62, 41, 12},
                      {29, 54, 71, 80, 81, 76, 63, 42, 13},
                      {28, 53, 70, 79, 78, 77, 64, 43, 14},
                      {27, 52, 69, 68, 67, 66, 65, 44, 15},
                      {26, 51, 50, 49, 48, 47, 46, 45, 16},
                      {25, 24, 23, 22, 21, 20, 19, 18, 17}};
  Show(spiral);
}
