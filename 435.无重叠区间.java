import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=435 lang=java
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length < 2)
            return 0;
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] x, int[] y) {
                if (x[1] != y[1]) {
                    return Integer.compare(x[1], y[1]);
                }
                else {
                    return Integer.compare(x[0], y[0]);
                }
            }
        });

        int count = 1;
        int edge = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (edge <= intervals[i][0]) {
                count++;
                edge = intervals[i][1];
            }
        }

        return intervals.length - count;
    }
}
// @lc code=end

