/*
 * @Author: jklash
 * @Description: 一年中的第几天
 * @Date: 2021-12-21 09:43:36
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-21 10:05:39
 */
/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
public:
    int dayOfYear(string date) {
        vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            months[1]++;
        }
        cout << month << endl;
        int ans = 0;
        for (int i = 0; i < month - 1; ++i) {
            ans += months[i];
        }
        return ans + day;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string date = "2000-03-01";
    cout << s.dayOfYear(date) << endl;
    return 0;
}
