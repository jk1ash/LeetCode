/*
 * @Author: jklash
 * @Description: 统计特殊四元组
 * @Date: 2021-12-29 09:33:21
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-29 10:55:03
 */
/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 *
 * [1995] 统计特殊四元组
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
/* 
    方法1：暴力枚举
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                for (int c = b + 1; c < n; ++c) {
                    for (int d = c + 1; d < n; ++d) {
                        if (nums[a] + nums[b] + nums[c] == nums[d])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
 */
// @lc code=start
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> cnt;
        for (int b = n - 3; b >= 1; --b) {
            for (int d = b + 2; d < n; ++d) {
                cnt[nums[d] - nums[b + 1]]++;
            }
            for (int a = 0; a < b; ++a) {
                int sum = nums[a] + nums[b];
                if (cnt.count(sum))
                    ans += cnt[sum];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {1,2,3,6};
    cout << s.countQuadruplets(nums) << endl;
    return 0;
}
