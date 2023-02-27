/*
 * @Author: jklash
 * @Description: 课程表 III
 * @Date: 2021-12-14 09:37:14
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-14 10:24:26
 */
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
        });
        
        priority_queue<int> q;
        int total = 0;

        for (auto& c : courses) {
            int t = c[0], d = c[1];
            if (total + t <= d) {
                total += t;
                q.push(t);
            } else if (!q.empty() && q.top() > t) {
                total -= q.top() - t;
                q.pop();
                q.push(t);
            }
        }
        return q.size();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> courses {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout << s.scheduleCourse(courses) << endl;
    return 0;
}
