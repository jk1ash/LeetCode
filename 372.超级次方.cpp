/*
 * @Author: jklash
 * @Description: 超级次方
 * @Date: 2021-12-05 09:59:25
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-05 11:02:32
 */
/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    int MOD = 1337;
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);
    }

    int dfs (int a, vector<int>& b, int pos) {
        if (pos == -1) return 1;
        return quickPow(dfs(a, b, pos - 1), 10) * quickPow(a, b[pos]) % MOD;
    }
    
    //快速幂
    int quickPow (int a, int b) {
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if ((b & 1) != 0) 
                ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int a = 2147483647; 
    vector<int> b {2,0,0};
    cout << s.superPow(a, b) << endl;
    return 0;
}
