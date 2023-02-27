/*
 * @Author: jklash
 * @Description: 石子游戏
 * @Date: 2021-11-12 14:13:21
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-12 14:52:40
 */
/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        auto dp = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        for (int l = n -2; l >= 0; --l) {
            for (int r = l + 1; r < n; r++) {
                // 取左边， 下一个的区间变为dp[l + 1][r]
                // 取右边，下一个的区间变为dp[l][r - 1]
                dp[l][r] = max(piles[l] - dp[l + 1][r], piles[r] - dp[l][r - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t = {3,2,10,4};
    cout << s.stoneGame(t) << endl;
    return 0;
}
