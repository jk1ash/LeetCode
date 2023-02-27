import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=119 lang=java
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
    public List<Integer> getRow(int rowIndex) {

        List<Integer> pre = new ArrayList<Integer>();

        for (int i = 0; i <= rowIndex; i++) {
            List<Integer> cur = new ArrayList<Integer>();
            for (int j = 0; j <=i; j++) {
                if (j == 0 || j == i) {
                    cur.add(1);
                }
                else {
                    cur.add(pre.get(j - 1) + pre.get(j));
                }
            }
            pre = cur;
        }
        return pre;
    }
}
// @lc code=end

