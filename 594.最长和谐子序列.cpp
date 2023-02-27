/*
 * @Author: jklash
 * @Description: 最长和谐子序列
 * @Date: 2021-11-21 11:07:10
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-21 11:23:50
 */
/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
/* 
    方法1 : 哈希表计数
    class Solution {
    public:
        int findLHS(vector<int>& nums) {
            unordered_map<int, int> map;
            for (auto& num : nums) {
                map[num]++;
            }
            int ans = 0;
            for (auto [key, val] : map) {
                if (map.count(key + 1)) {
                    ans = max(ans, map[key + 1] + val);
                }
            }
            return ans;
        }
    };
 */
/* 方法2: 滑动窗口 */
// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0 , j = 0; j < n; ++j) {
            while (i < j && nums[j] - nums[i] > 1) i++;
            if (nums[j] - nums[i] == 1)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
// @lc code=end

