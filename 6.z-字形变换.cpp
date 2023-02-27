/*
 * @Author: jklash
 * @Description: Z 字形变换
 * @Date: 2022-03-01 09:46:13
 * @LastEditors: jklash
 * @LastEditTime: 2022-03-01 11:41:27
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n)
            return s;
        vector<string> tmp(numRows);
        int i = 0, flag = -1;
        for (auto& c : s) {
            tmp[i] += c;
            // 先头部正向进行, 到行尾则反向
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        string ans;
        for (auto &t : tmp) {
            ans += t;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "PAYPALISHIRING";
    int num = 3;
    cout << s.convert(str, num) << endl;
    return 0;
}
