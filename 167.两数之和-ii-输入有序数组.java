import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length -1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                return new int[] {left+1, right+1};
            }
        }
        return new int[0];
    }
}
// @lc code=end

