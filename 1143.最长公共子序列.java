/*
 * @lc app=leetcode.cn id=1143 lang=java
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] f = new int[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            f[i][0] = 1;
        }
        for (int j = 0; j <= n; j++) {
            f[0][j] = 1;
        }
        for(int i = 1; i <= m; i++) {
            char c1 = text1.charAt(i-1);
            for (int j = 1; j <= n; j++) {
                char c2 = text2.charAt(j-1);
                if (c1 == c2) {
                    f[i][j] = f[i-1][j-1] + 1;
                } else {
                    f[i][j] = Math.max(f[i-1][j], f[i][j-1]);
                }
            }
        }
        return f[m][n] - 1;
    }
}
// @lc code=end

