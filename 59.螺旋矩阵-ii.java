/*
 * @lc app=leetcode.cn id=59 lang=java
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    public int[][] generateMatrix(int n) {
        int num = 1;
        int [][] matrix = new int[n][n];
        int left = 0, right = n -1, top = 0, bottom = n -1;
        while (left <= right && top <= bottom) {
            //上行
            for (int col = left; col <= right; col++) {
                matrix[top][col] = num;
                num++;
            }
            //右列
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && top < bottom) {
                //下行
                for (int col = right -1; col > left; col--) {
                    matrix[bottom][col] = num;
                    num++;
                }
                //左列
                for (int row  = bottom; row > top; row--) {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
}
// @lc code=end

