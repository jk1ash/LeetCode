/*
 * @Author: jklash
 * @Description: 剑指 Offer 42. 连续子数组的最大和
 * @Date: 2021-12-08 22:14:27
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-16 16:33:16
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if(dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }
        int ans = INT32_MIN;
        for (auto& d : dp) {
            ans = max(ans, d);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}