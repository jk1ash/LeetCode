/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-12 10:32:11
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-12 11:44:23
 */
/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        
        int dp[n + 1][n + 1];
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = INT32_MAX;
            }
        }

        for (int i = 0; i <= n; ++i)
            dp[i][i] = 0;
        
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i >= 1; --i) {
                for (int k = i + 1; k <= j - 1; ++k) {
                    dp[i][j] = min(max(dp[i][k -1], dp[k+1][j]) + k, dp[i][j]);
                }   
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + i);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + j);
            }
        }
        return dp[1][n];
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.getMoneyAmount(10) << endl;
    return 0;
}
