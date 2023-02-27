/*
 * @Author: jklash
 * @Description: 简化路径
 * @Date: 2022-01-06 10:07:03
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-06 11:19:37
 */
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // 定义分割函数， 将字符串以 / 分割
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (auto& c : s) {
                if (c == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                } else {
                    cur += c;
                }
            }
            ans.push_back(move(cur));
            return ans;
        }; 

        // 切割路径
        vector<string> names = split(path, '/');
        vector<string> stk;
        // 路径拆分存入栈中
        for (auto& name : names) {
            // 如果是指向上一层，则弹出栈顶
            if (name == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            // 不为空字符和当前目录时，存入栈
            } else if (!name.empty() && name != ".") {
                stk.push_back(move(name));
            }
        }
        string ans;
        // 栈空，返回根目录
        if (stk.empty()) {
            ans = "/";
        // 不为空，进行路径拼装
        } else {
            for (auto& name : stk) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "/a/./b/../../c/";
    cout << s.simplifyPath(str) << endl;
    return 0;
}

