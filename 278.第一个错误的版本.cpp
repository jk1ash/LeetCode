/*
 * @Author: jklash
 * @Description: 第一个错误的版本
 * @Date: 2021-12-15 14:27:15
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-15 14:39:36
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l == r && isBadVersion(l)) {
            return l;
        }
        return -1;
    }
};
// @lc code=end