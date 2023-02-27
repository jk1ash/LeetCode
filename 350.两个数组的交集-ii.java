import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=350 lang=java
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length) {
            return intersect(nums2, nums1);
        }
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int num : nums1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int[] ret = new int[nums1.length];
        int idx = 0;
        for (int num : nums2) {
            int count = map.getOrDefault(num, 0);
            if (count > 0) {
                ret[idx++] = num;
                count --;
                if (count > 0) {
                    map.put(num, count);
                }
                else
                {
                    map.remove(num);
                }
            }
        }
        return Arrays.copyOfRange(ret, 0, idx);
    }
}
// @lc code=end

