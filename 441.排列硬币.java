/*
 * @lc app=leetcode.cn id=441 lang=java
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
    public int arrangeCoins(int n) {
        long l = 1, r = n;
        while (l < r) {
            long m = l + r + 1 >> 1;
            if(m * (m + 1) / 2 <= n) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return (int) r;
    }
}
// @lc code=end

