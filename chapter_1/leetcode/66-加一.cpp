// @leet start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1, temp = 0, index = 0, size = digits.size();
    for (int i = 0; i < size; ++i) {
      temp = carry, index = size - 1 - i;
      carry = (digits[index] + carry) / 10;
      digits[index] = (temp + digits[index]) % 10;
      // cout << carry << " " << digits[i] << endl;
    }
    if (carry != 0) digits.insert(digits.begin(), carry);
    return digits;
  }
};
// @leet end
