/*
 * @Author: jklash
 * @Description: K 次取反后最大化的数组和
 * @Date: 2021-12-03 16:03:43
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-03 16:29:49
 */
/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans = 0;
        while (k > 0) {
            int idx = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < nums[idx])
                    idx = i;
            }
            nums[idx] = -nums[idx];
            k--;
        }
        
        for (auto num : nums) {
            ans += num;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {2,-3,-1,5,-4};
    int k = 2;
    cout << s.largestSumAfterKNegations(nums, k) << endl;
    return 0;
}
