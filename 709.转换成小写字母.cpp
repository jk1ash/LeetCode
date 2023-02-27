/*
 * @Author: jklash
 * @Description: 转换成小写字母
 * @Date: 2021-12-12 10:55:22
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-12 10:56:34
 */
/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        for (auto&c : s) {
            c = tolower(c);
        }
        return s;
    }   
};
// @lc code=end

