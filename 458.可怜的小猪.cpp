/*
 * @Author: jklash
 * @Description: 可怜的小猪
 * @Date: 2021-11-25 14:34:07
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-25 16:42:20
 */
/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie;
        int base = times + 1;
        double temp = log(buckets) / log(base);
        int ans = ceil(temp);
        return ans; 
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.poorPigs(4, 15, 15) << endl;
    return 0;
}

