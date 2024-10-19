#include <iostream>
using namespace std;
double Pow(double x, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    double temp = Pow(x, n / 2);
    return temp * temp;
  } else {
    double temp = Pow(x, n / 2);
    return temp * temp * x;
  }
}

int main() {
  cout << "输入基数：";
  double x;
  cin >> x;
  cout << "输入幂：";
  int n;
  cin >> n;
  cout << "求得：" << Pow(x, n) << "\n";
}
