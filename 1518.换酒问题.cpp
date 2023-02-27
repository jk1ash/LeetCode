/*
 * @Author: jklash
 * @Description: 换酒问题
 * @Date: 2021-12-17 10:01:23
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-17 10:22:51
 */
/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int numBottles = 9, numExchange = 3;
    cout << s.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}
