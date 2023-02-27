/*
 * @Author: jklash
 * @Description: 保持城市天际线
 * @Date: 2021-12-13 09:33:22
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-13 10:04:18
 */
/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r(n, 0);
        vector<int> c(m, 0);
        
        // 找出行列的最大值
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                r[i] = max(r[i], grid[i][j]);
                c[j] = max(c[j], grid[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(r[i], c[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid {{3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0}};
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}
