/*
 * @Author: jklash
 * @Description: 将一维数组转变成二维数组
 * @Date: 2022-01-06 11:21:26
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-06 11:48:03
 */
/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // 如果不够组成二维数组，返回空
        if (original.size() != m * n) 
            return {};

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0, idx = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = original[idx++];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t {1,2};
    int m = 1, n = 1;
    vector<vector<int>> ans = s.construct2DArray(t, m, n);
    cout << "[";
    for (auto& a : ans) {
        cout << "[";
        for (auto& b : a) {
            cout << b << ",";
        }
        cout << "\b \b],";
    }
    cout << "\b \b]" << endl;
    return 0;
}

