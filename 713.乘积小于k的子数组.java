/*
 * @lc app=leetcode.cn id=713 lang=java
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int prod = 1, left = 0, count = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while(left <= right && prod >= k)
                prod /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
}
// @lc code=end

