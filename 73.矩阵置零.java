/*
 * @lc app=leetcode.cn id=73 lang=java
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
    public void setZeroes(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        boolean row0 = false, col0 = false;
        
        //第一列是否有0
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }

        //第一行是否有0
        for (int j = 0; j < col; j++) {
            if(matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }

        //把第一行第一列作为标志位
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        //行和列置0
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] ==0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //标志位也置0
        if (col0) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
        if (row0) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

    }
}
// @lc code=end

