/*
 * @Author: jklash
 * @Description: 可见点的最大数目
 * @Date: 2021-12-16 09:36:27
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-16 15:16:02
 */
/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x = location[0], y = location[1];
        vector<double> list{};
        int cnt = 0;
        double pi = M_PI, t = angle * pi / 180;
        
        for (auto& p : points) {
            int a = p[0], b = p[1];
            // 与原点重合的点计数
            if (a == x && b == y && ++cnt > 0) 
                continue;
            // 计算极角列表
            list.push_back(atan2(b - y, a -x) + pi);
        }
        
        // 极角排序 
        sort(list.begin(), list.end());

        int n = list.size(), MAX = 0;
        for (int i = 0; i < n; ++i) {
            list.push_back(list[i] + 2 * pi);
        }
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            while (i < j && list[j] - list[i] > t) {
                i++;
            }
            MAX = max(MAX, j - i + 1);
        }
        return cnt + MAX;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> points {{1, 1}, {2, 2}, {1, 2}, {2, 1}};
    int angle = 0;
    vector<int> loca {1, 1};
    cout << s.visiblePoints(points, angle, loca) << endl; 
    return 0;
}
