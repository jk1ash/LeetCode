import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=438 lang=java
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<Integer>();
        int m = s.length(), n = p.length();
        if (m < n) 
            return ans;
        int[] sCnt = new int[26];
        int[] pCnt = new int[26];
        for (int i = 0; i < n; i++) {
            pCnt[p.charAt(i) - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < m; right++) {
            int curRight = s.charAt(right) - 'a';
            sCnt[curRight]++;
            while (sCnt[curRight] > pCnt[curRight]) {
                int curLeft = s.charAt(left) - 'a';
                sCnt[curLeft]--;
                left++;
            }
            if (right - left + 1 == n) {
                ans.add(left);
            }
        }
        return ans;
    }
}
// @lc code=end

