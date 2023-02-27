/*
 * @lc app=leetcode.cn id=557 lang=java
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int len = s.length();
        int i = 0;
        while (i < len) {
            int start = i;
            while (i < len && arr[i] != ' ') {
                i++;
            }
            int left = start, right = i - 1;
            while (left < right) {
                char tmp = arr[right];
                arr[right] = arr[left];
                arr[left] = tmp;
                left++;
                right--;
            }
            while (i < len && arr[i] == ' ') {
                i++;
            }
        }
        return new String(arr);
    }
}
// @lc code=end

