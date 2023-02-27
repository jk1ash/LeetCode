/*
 * @Author: jklash
 * @Description: 检测大写字母
 * @Date: 2021-11-13 09:42:49
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-13 10:01:55
 */
/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper = 0, lower = 0;
        for (auto& w : word) {
            if(w >= 'a' && w <= 'z') {
                lower++;
            } else {
                upper++;
            }
        }
        if (lower == n) {
            return true;
        } else if (upper == n) {
            return true;
        } else if (upper == 1 && word[0] < 'a') {
            return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.detectCapitalUse("Hello") << endl;
    return 0;
}


