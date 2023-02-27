/*
 * @Author: jklash
 * @Description: 猜数字大小
 * @Date: 2021-12-10 11:37:30
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-10 13:49:05
 */
/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) < 0) {
                right = mid - 1;
            } else if (guess(mid) > 0){
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end