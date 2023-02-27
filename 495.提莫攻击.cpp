/*
 * @Author: jklash
 * @Description: 提莫攻击
 * @Date: 2021-11-10 09:39:00
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-10 10:15:25
 */
/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;
        if (duration == 0) return ans;
        if (n == 0) return ans;
        for (int i = 1; i < n; ++i) {
            int a = timeSeries[i] - timeSeries[i-1];
            if ( a < duration) {
                ans += a;
            } else {
                ans += duration;
            }
        }
        ans += duration;
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t = {1,2,3,4,5};
    int d = 5;
    cout << s.findPoisonedDuration(t, d) << endl;    
    return 0;
}
