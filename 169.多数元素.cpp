/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int win = nums[0] ,count = 0;
        for (int num : nums) {
            if (win == num) {
                count++;
            } else if (count == 0) {
                win = num;
                count++;
            } else
                count--;
        }
        return win;
    }
};
// @lc code=end

