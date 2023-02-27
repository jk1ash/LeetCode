/*
 * @lc app=leetcode.cn id=273 lang=java
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
    String[] singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    String[] teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    String[] thousands = {"", "Thousand", "Million", "Billion"};
    
    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                StringBuffer cur = new StringBuffer();
                recursion(cur, curNum);
                cur.append(thousands[i]).append(" ");
                sb.append(cur);
            }
        }
        return sb.toString().trim();
    }

    public void recursion(StringBuffer cur, int num) {
        if (num == 0) {
            return;
        } else if (num < 10) {
            cur.append(singles[num]).append(" ");
        } else if (num < 20) {
            cur.append(teens[num - 10]).append(" ");
        } else if (num < 100) {
            cur.append(tens[num / 10]).append(" ");
            recursion(cur, num % 10);
        } else {
            cur.append(singles[num / 100]).append(" Hundred ");
            recursion(cur, num % 100);
        }
    }

}
// @lc code=end

