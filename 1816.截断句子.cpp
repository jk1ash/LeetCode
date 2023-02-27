/*
 * @Author: jklash
 * @Description: 截断句子
 * @Date: 2021-12-06 09:32:19
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 10:12:29
 */
/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0, end = 0, n = s.size();
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] == ' ') count++;
            if(count == k) {
                end = i;
                break;
            }
        }
        return s.substr(0, end);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "chopper is not a tanuki";
    int k = 5;
    cout << solution.truncateSentence(s, k) << endl;
    return 0;
}

