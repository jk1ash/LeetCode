/*
 * @Author: jklash
 * @Description: 数字范围按位与
 * @Date: 2021-11-17 16:29:29
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-17 16:59:22
 */
    /*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.rangeBitwiseAnd(0, 2147483647) << endl;
    return 0;
}
