import java.util.ArrayList;
import java.util.List;

import javax.print.DocFlavor.STRING;

/*
 * @lc app=leetcode.cn id=412 lang=java
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> res = new ArrayList<String>();
        for (int i = 1; i <= n; i++) {
            if (i%3 == 0 && i%5 == 0) {
                res.add("FizzBuzz");
            } else if (i%3 == 0) {
                res.add("Fizz");
            } else if (i%5 ==0) {
                res.add("Buzz");
            } else {
                res.add(Integer.toString(i));
            }
        }
        return res;
    }
}
// @lc code=end

