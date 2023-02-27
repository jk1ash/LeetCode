/*
 * @Author: jklash
 * @Description: 寻找峰值
 * @Date: 2021-12-15 14:53:39
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-15 15:10:50
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() ==0) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}

