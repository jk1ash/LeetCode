/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-27 10:38:22
 * @LastEditors: jklash
 * @LastEditTime: 2021-10-28 22:45:16
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
/*  
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    // 定义一个hashmap来存有效阔
    unordered_map<char, char> map = {
        {')', '('}, 
        {'}', '{'},
        {']', '['}
    };
    
    bool isValid(string s) {
        // 如果为奇数,直接返回错误 
        if (s.size() % 2 != 0)
            return false;

        stack<char> stk;
        for (char c : s) {
            // 查询是否包含右括号, 否则入栈
            if (map.count(c)) {
                // 但栈为空, 或者栈顶和hash表的值对应不上, 表明不是有效括号
                if (stk.empty() || stk.top() != map[c]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string test = "([{}])";
    cout << s.isValid(test);
    return 0;
}
