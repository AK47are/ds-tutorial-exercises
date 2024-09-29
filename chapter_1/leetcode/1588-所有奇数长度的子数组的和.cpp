class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0, left_even, right_even, left_odd, right_odd;
    for (int i = 0; i < arr.size(); ++i) {
      left_even = i / 2;
      right_even = (arr.size() - i - 1) / 2;
      left_odd = (i + 1) / 2;
      right_odd = (arr.size() - i) / 2;
      sum +=
          ((left_even + 1) * (right_even + 1) + left_odd * right_odd) * arr[i];
    }
    return sum;
  }
};
