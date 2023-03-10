import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=560 lang=java
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count  = 0, pre = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, 1);
        for(int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if(map.containsKey(pre - k))
                count += map.get(pre -k);
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }
        return count;
    }
}
// @lc code=end

