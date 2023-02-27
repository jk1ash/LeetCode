import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=118 lang=java
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        int[][] dp = new int[numRows][numRows];

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<Integer>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                row.add(dp[i][j]);
            }
            ret.add(row);
        }
        return ret;
    }
}
// @lc code=end

