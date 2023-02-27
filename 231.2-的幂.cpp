/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-28 11:36:37
 * @LastEditors: jklash
 * @LastEditTime: 2022-02-28 15:23:59
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (-n)) == n;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 4;
    cout << s.isPowerOfTwo(n) << endl;
    return 0;
}
