/*
 * @Author: jklash
 * @Description:找到小镇的法官
 * @Date: 2021-12-20 10:38:42
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-20 10:47:58
 */

/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0) return -1;
        vector<int> in(n + 1), out(n + 1);
        for (auto& t : trust) {
            int x = t[0], y = t[1];
            in[y]++;
            out[x]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 3;
    vector<vector<int>> trust {{1,3},{2,3}};
    cout << s.findJudge(n, trust) << endl;
    return 0;
}
