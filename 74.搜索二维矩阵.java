/*
 * @lc app=leetcode.cn id=74 lang=java
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int index = binarySearchFirstCol(matrix, target);
        if(index < 0)
            return false;
        return binarySearchRow(matrix[index], target);
    }
    
    public int binarySearchFirstCol(int[][] matrix, int target) {
        int l = -1, r = matrix.length - 1;
        while (l < r) {
            int m = l + ((r - l + 1) >> 1);
            if (matrix[m][0] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    public boolean binarySearchRow(int[] row, int target) {
        int l = 0, r = row.length - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (row[m] == target) {
                return true;
            }
            else if (row[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
}
// @lc code=end

