/*
 * @Author: jklash
 * @Description: 整数替换
 * @Date: 2021-11-19 09:22:25
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-19 10:08:08
 */
/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<long, int> map;
    int integerReplacement(int n) {
        return dfs(n * 1L);
    }

    int dfs(long n) {
        if (n == 1) return 0;
        if (map.count(n)) return map[n];
        int ans;
        if (n % 2 == 0) {
            ans = dfs(n / 2);
        } else {
            ans = min(dfs(n + 1), dfs(n - 1));
        }
        map[n] = ++ans;
        return ans;
    }

};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.integerReplacement(7) << endl;
    return 0;
}
