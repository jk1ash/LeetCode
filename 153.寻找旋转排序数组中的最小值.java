/*
 * @lc app=leetcode.cn id=153 lang=java
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = left + (right - left)/2 ;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
}
// @lc code=end

