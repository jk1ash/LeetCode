/*
 * @lc app=leetcode.cn id=476 lang=java
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
    public int findComplement(int num) {
        int pos = -1;
        for (int i = 31; i >= 0; i--) {
            if (((num >> i) & 1) != 0) {
                pos = i;
                break;
            }
        }
        for(int i = pos; i >= 0; i--) {
            num ^= (1 << i);
        }
        return num;
    }
}
// @lc code=end

