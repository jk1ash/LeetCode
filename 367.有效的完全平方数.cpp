/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-05 16:34:17
 * @LastEditTime: 2021-11-05 17:08:17
 */
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = 1;
        while (num > 0)
        {
            num -= x;
            x += 2;
        }
        return num == 0;
    }
};
// @lc code=end

