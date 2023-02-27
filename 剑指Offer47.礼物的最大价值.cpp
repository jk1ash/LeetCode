/*
 * @Author: jklash
 * @Description: 剑指 Offer 47. 礼物的最大价值
 * @Date: 2021-12-16 16:39:04
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-16 17:33:43
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) continue;
                if (i == 0 && j != 0) {
                    dp[i][j] += grid[i][j] + dp[i][j - 1];
                } else if (i != 0 && j == 0) {
                    dp[i][j] += grid[i][j] + dp[i - 1][j];
                } else {
                    dp[i][j] += grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.maxValue(grid) << endl;
    return 0;
}
