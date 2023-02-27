import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=187 lang=java
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ret = new ArrayList<String>();
        int len = s.length();
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i + 10 <= len; i++) {
            String cur = s.substring(i, i+ 10);
            int cnt = map.getOrDefault(cur, 0);
            if (cnt == 1)
                ret.add(cur);    
            map.put(cur, cnt + 1);
        }
        return ret;
    }
}
// @lc code=end

