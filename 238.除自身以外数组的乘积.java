/*
 * @lc app=leetcode.cn id=238 lang=java
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] output = new int[len];
        
        output[0] = 1;
        for (int i = 1; i < len; i++) {
            output[i] = nums[i - 1] * output[i- 1];
        }

        int R = 1;
        for (int i = len - 1; i >= 0; i--) {
            output[i] = output[i] * R;
            R *= nums[i];
        }
        return output;
    }
}
// @lc code=end

