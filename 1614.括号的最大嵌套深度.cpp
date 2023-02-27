/*
 * @Author: jklash
 * @Description: 括号的最大嵌套深度
 * @Date: 2022-01-07 09:26:42
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-07 09:38:54
 */
/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "(1+(2*3)+((8)/4))+1";
    cout << s.maxDepth(str) << endl;
    return 0;
}
