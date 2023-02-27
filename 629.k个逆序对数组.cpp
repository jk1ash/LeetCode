/*
 * @Author: jklash
 * @Description: K个逆序对数组
 * @Date: 2021-11-11 10:42:08
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-11 15:43:50
 */
/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mod = (int)1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(n + 1, vector<int>(k + 1)), sum(n + 1, vector<int>(k + 1));
        f[1][0] = 1;
        fill(sum[1].begin(), sum[1].end(), 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = j < i ? sum[i - 1][j] : 
                          (sum[i - 1][j] - sum[i - 1][j - (i - 1) - 1] + mod) % mod;
                sum[i][j] = j == 0 ? f[i][j] : 
                            (sum[i][j - 1] + f[i][j]) % mod;
            }
        }
        return f[n][k];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.kInversePairs(1000, 1000) << endl;
    return 0;
}
