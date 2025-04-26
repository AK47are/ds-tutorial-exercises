#include "dependency.h"

template <int MAX>
class SMatrix : public SqList<int, MAX*(MAX + 1) / 2> {
  using List = SqList<int, MAX*(MAX + 1) / 2>;

 private:
  using List::Erase;
  using List::Insert;
  using List::operator[];

 protected:
  int GetIndex(int row, int col) const {
    if (row > col) return GetIndex(col, row);
    return (row + 1) * (2 * MAX - row) / 2 - (MAX - col - 1) - 1;
  }

 public:
  using SqList<int, MAX*(MAX + 1) / 2>::SqList;
  SMatrix(const int A[MAX][MAX]) {
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j) {
        if (i <= j) Insert(A[i][j], this->Size());
      }
    }
  }

  int GetOrder() const { return MAX; }

  int& GetValue(int row, int col) {
    return this->operator[](GetIndex(row, col));
  }

  const int& GetValue(int row, int col) const {
    return this->operator[](GetIndex(row, col));
  }

  SMatrix operator+(const SMatrix& t) const {
    SMatrix rtn;
    for (int i = 0; i < t.Size(); ++i) {
      rtn.Insert(this->operator[](i) + t.operator[](i), rtn.Size());
    }
    return rtn;
  }

  friend std::ostream& operator<<(std::ostream& os, const SMatrix& t) {
    for (int i = 0; i < t.GetOrder(); ++i) {
      for (int j = 0; j < t.GetOrder(); ++j) {
        os << " " << t.GetValue(i, j);
      }
      os << "\n";
    }
    return os;
  }
};

template <int MAX>
void Multiple(const SMatrix<MAX>& t1, const SMatrix<MAX>& t2) {
  int arr[MAX][MAX];
  // 左矩阵的第 i 行。
  for (int left_row = 0; left_row < MAX; ++left_row) {
    // 右矩阵的第 j 列。
    for (int right_col = 0; right_col < MAX; ++right_col) {
      int sum = 0;
      // 左矩阵的第 k 列。
      for (int left_col = 0; left_col < MAX; ++left_col) {
        sum +=
            t1.GetValue(left_row, left_col) * t2.GetValue(left_col, right_col);
      }
      arr[left_row][right_col] = sum;
    }
  }
  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      std::cout << " " << arr[i][j];
    }
    std::cout << "\n";
  }
}

int main() {
  using namespace std;
  int a[4][4] = {{1, 2, 3, 4}, {2, 5, 6, 7}, {3, 6, 8, 9}, {4, 7, 9, 10}};
  int b[4][4] = {{1, 1, 2, 2}, {1, 3, 3, 4}, {2, 3, 4, 5}, {2, 4, 5, 6}};
  SMatrix A(a), B(b);
  cout << "A: \n";
  cout << A;
  cout << "B: \n";
  cout << B;
  cout << "A + B: \n";
  cout << A + B;
  cout << "A * B: \n";
  Multiple(A, B);
}
