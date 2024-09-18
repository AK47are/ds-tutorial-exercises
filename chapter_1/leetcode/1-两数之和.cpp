// @leet start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> index(2), temp(nums.size());
    index[0] = 0, index[1] = nums.size() - 1;
    for (int i = 0; i < nums.size(); ++i) {
      temp[i] = nums[i];
    }
    int sum, flag = 0;
    sort(nums.begin(), nums.end());
    while (true) {
      sum = nums[index[0]] + nums[index[1]];
      // cout << sum << " " << index[0] << " " << index[1] << "\n";
      if (sum == target) {
          int n1 = nums[index[0]], n2 = nums[index[1]];
        if (nums[index[0]] != nums[index[1]])
          for (int i = 0; i < nums.size(); ++i) {
            if (temp[i] == n1) index[0] = i;
            if (temp[i] == n2) index[1] = i;
            // cout << index[0] << " " << index[1] << "\n";
          }
        else
          for (int i = 0; i < nums.size(); ++i) {
            cout << temp[i] << " " << flag << "\n";
            if (temp[i] == n1 && flag == 0) {
              flag = 1;
              index[0] = i;
            }
            if (temp[i] == n2 && flag == 1) index[1] = i;
          }
        sort(index.begin(), index.end());
        return index;
      }
      if (sum > target)
        --index[1];
      else 
        ++index[0];
    }
  }
};
// @leet end
