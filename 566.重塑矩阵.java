/*
 * @lc app=leetcode.cn id=566 lang=java
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length;
        int n = mat[0].length;
        if (m * n != r * c) {
            return mat;
        }
        int[][] ret = new int[r][c];
        int midx = 0, nidx = 0;
        for (int i =0; i< r; i++) {
            for (int j = 0; j < c; j++) {
                ret[i][j] = mat[midx][nidx++];
                if(nidx == n) {
                    nidx = 0;
                    midx++;
                }
            }
        }
        return ret;
    }
}
// @lc code=end

