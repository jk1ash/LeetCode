/*
 * @Author: jklash
 * @Description: 复数乘法
 * @Date: 2022-02-25 16:09:25
 * @LastEditors: jklash
 * @LastEditTime: 2022-02-25 16:38:36
 */
/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, a2, b1, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string n1 = "1+1i", n2 = "1+1i";
    cout << s.complexNumberMultiply(n1, n2) << endl;
    return 0;
}
