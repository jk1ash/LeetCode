/*
 * @lc app=leetcode.cn id=334 lang=java
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
    public boolean increasingTriplet(int[] nums) {
        if (nums.length < 3) 
            return false;
        int min = Integer.MAX_VALUE, mid = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num <= min) {
                min = num;
            }
            else if (num <= mid) {
                mid = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end

