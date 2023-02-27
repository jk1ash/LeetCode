/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-07 16:16:48
 * @LastEditTime: 2021-11-07 16:30:28
 */
/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto &op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);            
        }
        return m * n;
    }
};
// @lc code=end

