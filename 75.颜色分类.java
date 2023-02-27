/*
 * @lc app=leetcode.cn id=75 lang=java
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
        int len = nums.length;
        int left  = 0, right = len - 1;
        quickSort(nums, left, right);
    }
    private void quickSort(int[] nums, int left, int right) {
        if (left < right) {
            int x = nums[left];
            int i = left;
            int j = right;
            while (i < j) {
                while (i < j && nums[j] > x) {
                    j--;
                }
                if(i < j) {
                    nums[i] = nums[j];
                    i++;
                }
                while (i < j && nums[i] < x) {
                    i++;
                }
                if (i < j) {
                    nums[j] = nums[i];
                    j-- ;
                }
            }
            nums[i] = x;
            quickSort(nums, left, i-1);
            quickSort(nums, i+1, right);
        }
    }
}
// @lc code=end

