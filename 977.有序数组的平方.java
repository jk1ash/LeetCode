import java.lang.reflect.Array;

/*
 * @lc app=leetcode.cn id=977 lang=java
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
    public int[] sortedSquares(int[] nums) {
        int len = nums.length;
        int[] ret = new int[len];
        for (int i = 0, j = len-1, k = len-1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ret[k] = nums[i] * nums[i];
                i++;
            }
            else {
                ret[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }
        return ret;
    }
}
// @lc code=end

