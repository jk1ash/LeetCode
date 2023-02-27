/*
 * @Author: jklash
 * @Description: 适龄的朋友
 * @Date: 2021-12-27 11:46:09
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-27 11:58:55
 */
/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    bool check(int x, int y) {
        if (y <= 0.5 * x + 7)
            return false;
        if (y > x)
            return false;
        if (y > 100 && x < 100)
            return false;
        return true;
    }

public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(), ans = 0;
        sort(ages.begin(), ages.end());
        for (int i = 0, j = 0, k = 0; k < n; ++k) {
            while (i < k && !check(ages[i], ages[k])) i++;
            if (j < k) j = k;
            while (j < n && check(ages[j], ages[k])) j++;
            if (j > i) ans += j - i - 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ages {20,30,100,110,120};
    cout << s.numFriendRequests(ages) << endl;
    return 0;
}
