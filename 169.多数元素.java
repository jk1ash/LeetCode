import java.lang.reflect.Array;
import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=169 lang=java
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
    public int majorityElement(int[] nums) {
        int vote = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (vote == nums[i]) {
                count++;
            } else
                count--; 
            if (count == 0) {
                vote = nums[i];
                count = 1;
            }
        }
        return vote;
    }
}
// @lc code=end

