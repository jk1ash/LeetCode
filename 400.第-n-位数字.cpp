/*
 * @Author: jklash
 * @Description: 第 N 位数字
 * @Date: 2021-11-30 09:55:35
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-30 10:22:01
 */
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    int totalDigits(int length) {
        int digits = 0;
        int curLength = 1, curCount = 9;
        while (curLength <= length) {
            digits += curLength * curCount;
            curLength++;
            curCount *= 10;
        }
        return digits;
    }

public:
    int findNthDigit(int n) {
        int left = 0, right = 9;
        while (left < right) {
            int mid  = left + ((right - left) >> 1);
            if (totalDigits(mid) < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int d = left;
        int prevDigits = totalDigits(d - 1);
        int index = n - prevDigits - 1;
        int start = (int) pow(10, d - 1);
        int num = start + index / d;
        int digitsIndex = index % d;
        int digits = (num / (int) (pow (10, d - digitsIndex - 1))) % 10;
        return digits;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int t = 11;
    cout << s.findNthDigit(t) << endl;
    return 0;
}
