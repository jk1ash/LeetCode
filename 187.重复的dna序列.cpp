/*
 * @Author: jklash
 * @Description: 重复的DNA序列
 * @Date: 2021-12-27 15:18:57
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-27 16:41:35
 */
/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans {};
        int n  = s.size();
        unordered_map<string, int> map;
        for (int i = 0; i + 10 <= n; ++i) {
            string cur = s.substr(i, 10);
            if (++map[cur] == 2) {
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "AAAAAAAAAAA";
    vector<string> ans;
    ans = s.findRepeatedDnaSequences(str);
    cout << "[";
    for (auto& a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" << "]" <<endl;
    return 0;
}
