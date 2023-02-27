import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=387 lang=java
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {
        if (s == null) {
            return -1;
        }

        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            if(map.containsKey(ch)) {
                map.put(ch, -1);
            }
            else {
                map.put(ch, i);
            }
        }

        int ret = len;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            int pos = entry.getValue();
            if (pos != -1 && pos < ret) {
                ret = pos;
            }
        }
        if (ret == len) {
            return -1;
        }
        return  ret;
    } 
}
// @lc code=end

