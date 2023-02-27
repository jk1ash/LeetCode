/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-06 13:03:01
 * @LastEditTime: 2021-11-06 13:26:06
 */
/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;
        for (int a : arr) {
           dp[a] = dp[a - difference] + 1;
           ans = max(ans, dp[a]); 
        }
        return ans;
    }
};
// @lc code=end

