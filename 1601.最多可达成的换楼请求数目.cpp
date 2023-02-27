/*
 * @Author: jklash
 * @Description: 最多可达成的换楼请求数目
 * @Date: 2022-02-28 14:07:56
 * @LastEditors: jklash
 * @LastEditTime: 2022-02-28 15:16:59
 */
/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        auto check = [=] (int s) {
            vector<int> cnt(20);
            int sum = 0;
            for (int i = 0; i < 16; ++i) {
                if ((s >> i) & 1 == 1) {
                    int a = requests[i][0], b = requests[i][1];
                    if (++cnt[a] == 1) sum++;
                    if (--cnt[b] == 0) sum--;
                }
            }
            return sum == 0;
        };

        auto getCnt = [=] (int s) {
            int ans = 0;
            for (int i = s; i > 0; i -= (i & -i))
                ans++;
            return ans;
        };

        int m = requests.size(), ans = 0;
        for (int i = 0; i < (1 << m); ++i) {
            int cnt = getCnt(i);
            if (cnt <= ans) 
                continue;
            if (check(i))
                ans = cnt;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 3;
    vector<vector<int>> r{{0,1}, {1,0}, {0,1}, {1,2}, {2,0}, {3,4}};
    cout << s.maximumRequests(n, r) << endl;
    return 0;
}
