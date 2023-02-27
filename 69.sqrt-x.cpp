/*
 * @Author: jklash
 * @Description: Sqrt(x)
 * @Date: 2021-12-10 11:06:50
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-10 11:30:20
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 0, right = x ,ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int x = 2147395599;
    cout << s.mySqrt(x) << endl;
    return 0;
}
