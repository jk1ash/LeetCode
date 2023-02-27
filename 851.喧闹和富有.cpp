/*
 * @Author: jklash
 * @Description: 喧闹和富有
 * @Date: 2021-12-15 10:33:34
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-15 11:44:58
 */
/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> in(n);

        for (auto& r : richer) {
            g[r[0]].emplace_back(r[1]);
            ++in[r[1]];
        }

        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.emplace(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto& y : g[x]) {
                if (quiet[ans[x]] < quiet[ans[y]]) {
                    ans[y] = ans[x];
                }
                if (--in[y] == 0) {
                    q.emplace(y);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> richer{};
    vector<int> quiet{};
    vector<int> ans;
    ans = s.loudAndRich(richer, quiet);
    cout << "[";
    for (auto& a : ans) {
        cout << a << ",";
    }
    cout << "\b \b]" << endl;
    return 0;
}
