/*
 * @Author: jklash
 * @Description: 连续字符
 * @Date: 2021-12-01 10:04:44
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-01 11:57:12
 */
/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 1, count = 0;
        for (int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            if (s[i] == s[j])
                count++;
            else
                count = 0;
            ans = max(ans, count + 1);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string t = "abbcccddddeeeeedcba";
    cout << s.maxPower(t) <<endl;
    return 0;
}
