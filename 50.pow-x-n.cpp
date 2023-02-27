/*
 * @Author: jklash
 * @Description: 快速幂
 * @Date: 2021-12-05 10:07:41
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-05 10:21:21
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0f) return double(0.0);
        long b = n;
        double res = 1.0;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        while (b > 0) {
            if (b & 1 == 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    double x = 2.10000;
    int n = 3;
    cout << s.myPow(x, n) << endl;
    return 0;
}
