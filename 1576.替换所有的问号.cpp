/*
 * @Author: jklash
 * @Description: 替换所有的问号
 * @Date: 2022-01-06 09:43:20
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-06 10:03:39
 */
/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'c'; ++c) {
                    if ((i > 0 && s[i - 1] == c) || (i < n && s[i + 1] == c))
                        continue;
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "ubv?w";
    cout << s.modifyString(str) << endl;
    return 0;
}
