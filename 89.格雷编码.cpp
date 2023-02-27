/*
 * @Author: jklash
 * @Description: 格雷编码 
 * @Date: 2022-01-08 17:54:38
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-08 18:03:10
 */
/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve(1 << n);
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int m = ans.size();
            for (int j = m -1; j >= 0; --j) {
                ans.push_back(ans[j] | (1 << (i - 1)));
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 2;
    vector<int> ans = s.grayCode(n);
    cout << "[";
    for (auto& a : ans) {
        cout << a << ",";
    }
    cout << "\b \b]" << endl;
    return 0;
}
