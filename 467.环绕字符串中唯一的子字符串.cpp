/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> dp(26);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {
                ++m;
            }else {
                m = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], m);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string p = "cac";
    cout << s.findSubstringInWraproundString(p) << endl;
    return 0;
}
