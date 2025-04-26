// @leet start
class Solution {
 public:
  string addBinary(string a, string b) {
    string res;
    auto a_cur = a.rbegin(), b_cur = b.rbegin();
    int carry = 0;
    while (a_cur != a.rend() && b_cur != b.rend()) {
      res.insert(res.begin(), (*a_cur + *b_cur + carry) % 2 + '0');
      carry = (*a_cur + *b_cur + carry - 2 * '0') / 2;
      ++a_cur, ++b_cur;
    }
    while (a_cur != a.rend()) {
      res.insert(res.begin(), (*a_cur + carry - '0') % 2 + '0');
      carry = (*a_cur + carry - '0') / 2;
      ++a_cur;
    }
    while (b_cur != b.rend()) {
      res.insert(res.begin(), (*b_cur + carry - '0') % 2 + '0');
      carry = (*b_cur + carry - '0') / 2;
      ++b_cur;
    }
    if (carry != 0) res.insert(res.begin(), carry + '0');
    while (*res.begin() == 0) res.erase(res.begin());
    return res;
  }
};
// @leet end
