#include<vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
      int ans = 0, m = 2e9;
      for (int n : nums)
        m = min(m, n);
      for (int n : nums) {
        ans += n - m;
      }
      return ans;
    }
};
// @lc code=end

