// TODO: 修改代码,使三元组顺序存储。修改矩阵转置算法。
#include <iostream>
#include <ostream>

#include "dependency.h"
struct TupNode {
  size_t row;
  size_t col;
  int data;

  TupNode operator+(const TupNode& t) {
    return TupNode{row, col, data + t.data};
  }
  friend std::ostream& operator<<(std::ostream& os, const TupNode& node) {
    os << " (" << node.row << ", " << node.col << ", " << node.data << ") ";
    return os;
  }
};

template <size_t MAX>
class TSMatrix : public SqList<TupNode, MAX * MAX> {
  using List = SqList<TupNode, MAX * MAX>;

 private:
  using List::Erase;
  using List::Insert;
  using List::operator[];

 public:
  using SqList<TupNode, MAX * MAX>::SqList;
  TSMatrix(const int A[MAX][MAX]) {
    for (size_t i = 0; i < MAX; ++i) {
      for (size_t j = 0; j < MAX; ++j) {
        if (A[i][j] != 0) Insert(TupNode{i, j, A[i][j]}, this->Size());
      }
    }
  }

  bool IsHas(size_t row, size_t col) const {
    for (int i = 0; i < this->Size(); ++i) {
      if (this->GetArr()[i].row == row && this->GetArr()[i].col == col)
        return true;
    }
    return false;
  }

  size_t GetOrder() const { return MAX; }

  TupNode GetNode(size_t row, size_t col) const {
    for (int i = 0; i < this->Size(); ++i) {
      if (this->GetArr()[i].row == row && this->GetArr()[i].col == col)
        return this->GetArr()[i];
    }
    return TupNode{0, 0, 0};
  }

  void Transpose() {
    int temp;
    for (int i = 0; i < this->Size(); ++i) {
      temp = this->GetArr()[i].row;
      this->GetArr()[i].row = this->GetArr()[i].col;
      this->GetArr()[i].col = temp;
    }
  }

  TSMatrix operator+(const TSMatrix& t) const {
    TSMatrix rtn;
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j) {
        bool has = this->IsHas(i, j), t_has = t.IsHas(i, j);
        if (has && t_has) {
          // std::cout << i << " " << j << "\n";
          rtn.Insert(this->GetNode(i, j) + t.GetNode(i, j), rtn.Size());
        } else if (has)
          rtn.Insert(this->GetNode(i, j), rtn.Size());
        else if (t_has)
          rtn.Insert(t.GetNode(i, j), rtn.Size());
      }
    }
    return rtn;
  }

  TSMatrix operator*(const TSMatrix& t) const {
    TSMatrix rtn;
    // 左矩阵的第 i 行。
    for (size_t left_row = 0; left_row < MAX; ++left_row) {
      // 右矩阵的第 j 列。
      for (size_t right_col = 0; right_col < MAX; ++right_col) {
        int sum = 0;
        // 左矩阵的第 k 列。
        for (size_t left_col = 0; left_col < MAX; ++left_col) {
          bool has = this->IsHas(left_row, left_col),
               t_has = t.IsHas(left_col, right_col);
          if (has && t_has) {
            sum += this->GetNode(left_row, left_col).data *
                   t.GetNode(left_col, right_col).data;
          }
        }
        if (sum != 0) rtn.Insert(TupNode{left_row, right_col, sum}, rtn.Size());
      }
    }
    return rtn;
  }

  friend std::ostream& operator<<(std::ostream& os, const TSMatrix& t) {
    for (int i = 0; i < t.GetOrder(); ++i) {
      for (int j = 0; j < t.GetOrder(); ++j) {
        os << " ";
        if (t.IsHas(i, j))
          os << t.GetNode(i, j).data;
        else
          os << "0";
      }
      os << "\n";
    }
    return os;
  }
};

using namespace std;
int main() {
  int a[4][4] = {{1, 0, 3, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}};
  int b[4][4] = {{3, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 2}};
  TSMatrix<4> A(a), B(b);
  cout << "A: \n" << A << "B: \n" << B;
  A.Transpose();
  cout << "A 转置后：\n" << A;
  A.Transpose();
  cout << "A + B: \n" << A + B;
  cout << "A * B: \n" << A * B;
}

// template <int M, int N>
// class TSMatrix {
//   vector<TupNode> arr_;
//
//  public:
//   TSMatrix() = default;
//   TSMatrix(const int A[M][N]) {
//     for (int i = 0; i < M; ++i) {
//       for (int j = 0; j < N; ++j) {
//         if (A[i][j] != 0) arr_.push_back(TupNode{i, j, A[i][j]});
//       }
//     }
//   }
//
//   vector<TupNode>& GetArr() { return arr_; }
//
//   TSMatrix<N, M> Transpose() {
//     TSMatrix<N, M> B;
//     int num[N];
//     int cpot[N];
//     fill(num, num + N, 0);
//     fill(cpot, cpot + N, 0);
//     for (auto cur : arr_) ++num[cur.col];
//     for (int i = 1; i < N; ++i) cpot[i] = cpot[i - 1] + num[i - 1];
//     B.GetArr().resize(arr_.size());
//     for (int i = 0; i < arr_.size(); ++i) {
//       B.GetArr()[cpot[arr_[i].col]] =
//           TupNode{arr_[i].col, arr_[i].row, arr_[i].data};
//       ++cpot[arr_[i].col];
//     }
//     return B;
//   }
//
//   friend std::ostream& operator<<(std::ostream& os, const TSMatrix<M, N>& t)
//   {
//     int cur = 0;
//     for (int i = 0; i < M; ++i) {
//       for (int j = 0; j < N; ++j) {
//         cout << " ";
//         if (t.arr_[cur].row == i && t.arr_[cur].col == j)
//           cout << t.arr_[cur++].data;
//         else
//           cout << 0;
//       }
//       cout << "\n";
//     }
//     return os;
//   }
