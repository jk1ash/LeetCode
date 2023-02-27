import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ret = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return ret;
        }
        int rows = matrix.length, cols = matrix[0].length;
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while(left <= right && top <= bottom) {
            for(int col = left; col <= right; col++) {
                ret.add(matrix[top][col]);
            }
            for(int row = top + 1; row <= bottom; row++) {
                ret.add(matrix[row][right]);
            }
            if(left < right && top < bottom) {
                for(int col = right - 1; col > left; col--) {
                    ret.add(matrix[bottom][col]);
                }
                for(int row = bottom; row > top; row--) {
                    ret.add(matrix[row][left]);
                }
            }
            
            left++;
            right--;
            top++;
            bottom--;
        } 
        return ret;
    }
}
// @lc code=end

