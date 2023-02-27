/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-27 20:59:51
 * @LastEditors: jklash
 * @LastEditTime: 2021-10-28 22:10:35
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        if (n == 0)
            return ans;
        
        dfs("", n, n, ans);
        return ans;
    }

    /* 
        curStr  当前递归得到的结果
        left    左括号可用数量
        right   右括号可用数量
        ans     结果集    
     */
    void dfs (string curStr, int left, int right, vector<string>& ans) {
        // 当递归终止,即左右括号都用完时,将curStr加入结果集
        if (left == 0 && right == 0) {
            ans.push_back(curStr);
            return;
        }

        // 当左括号大于右括号,进行剪枝
        if (left > right)
            return;

        if (left > 0) 
            dfs(curStr + "(", left - 1, right, ans);
        
        if (right > 0)
            dfs(curStr + ")", left, right - 1, ans);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 3;
    for (auto a : s.generateParenthesis(n))
        cout << "[" << a << "," << "]";
    return 0;
}
