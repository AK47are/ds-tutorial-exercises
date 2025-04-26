// @leet start
#include <climits>
// #include <iostream>
using namespace std;
class Solution {
 public:
  int reverse(int x) {
    int max = INT_MAX;
    int min = INT_MIN;
    int div = 1;
    for (int i = 0; i < 9; ++i) div *= 10;
    // cout << max << "\n";
    // cout << min << "\n";
    int result = 0, digit = 0, isOver = 0;
    bool isNegative = (x < 0);
    if (x == INT_MIN || x == INT_MAX) return 0;
    while (x != 0) {
      if (digit == 9 && isOver == 1) return 0;
      result *= 10, result += x % 10;
      if (isOver != -1 && isOver != 1) {
        if (isNegative == 0) {
          if (max / div < x % 10)
            isOver = 1;
          else if (max / div > x % 10)
            isOver = -1;
        } else {
          if (min / div > x % 10)
            isOver = 1;
          else if (min / div < x % 10)
            isOver = -1;
          // cout << min / div << " " << -x % 10 << "\n";
        }
      }
      ++digit, max %= div, min %= div, div /= 10, x /= 10;
      // cout << digit << " " << isOver << endl;
      // cout << result << " " << x << endl;
    }
    return result;
  }
};
// @leet end
