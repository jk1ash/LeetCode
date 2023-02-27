/*
 * @lc app=leetcode.cn id=443 lang=java
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
    public int compress(char[] chars) {
        int len = chars.length;
        int write = 0, left = 0;
        for (int read = 0; read < len; read++) {
            if (read == len -1 || chars[read] != chars[read+1]) {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1) {
                    int anchar = write;
                    while (num !=0) {
                        chars[write++] = (char) ((num % 10) + '0');
                        num /= 10;
                    }
                    reverse(chars, anchar, write-1);
                }
                left = read + 1;
            }
        }
        return write;
    }

    public void reverse(char[] chars, int left, int right) {
        while(left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
    }
}
// @lc code=end

