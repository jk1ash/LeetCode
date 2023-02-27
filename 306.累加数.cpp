/*
 * @Author: jklash
 * @Description: 累加数
 * @Date: 2022-01-10 09:50:39
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-10 11:04:15
 */
/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string tmp;
    int n;
    vector<vector<int>> list;
    bool isAdditiveNumber(string num) {
        tmp = num;
        n = num.size();        
        return dfs(0);
    }

    bool dfs(int u){
        auto check = [] (vector<int>& a, vector<int>& b, vector<int>& c) -> bool {
            vector<int> ans;
            int t = 0;
            for (int i = 0; i < a.size() || i < b.size(); ++i) {
                if (i < a.size()) t += a[i];
                if (i < b.size()) t += b[i];
                ans.emplace_back(t % 10);
                t /= 10;
            }
            if (t) ans.emplace_back(1);  // 处理最高位的进位
            bool ok = (c.size() == ans.size()); // 检查长度
            for (int i = 0; i < c.size() && ok; ++i) { 
                // 逐位检查
                if (c[i] != ans[i])
                    ok = false; 
            }
            return ok;
        };

        int m = list.size();
        if (u == n) 
            return m >= 3;
        int max = tmp[u] == '0' ? u + 1 : n;
        vector<int> cur;
        for (int i = u; i < max; ++i) {
            cur.insert(cur.begin(), tmp[i] - '0');
            if (m < 2 or check(list[m - 2], list[m - 1], cur)) {
                list.emplace_back(cur);
                if (dfs(i + 1))
                    return true;
                list.pop_back();
            }
        } 
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string num = "199100199";
    cout << s.isAdditiveNumber(num) << endl;
    return 0;
}
