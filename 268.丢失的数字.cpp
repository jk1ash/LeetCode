/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*  方法1: 排序
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }
        return n;       
    }
};

*/

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i && nums[i] < n)
                swap(nums, nums[i], i--);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }
        return n;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
// @lc code=end

