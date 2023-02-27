/*
 * @Author: jklash
 * @Description: 剑指 Offer 10- II. 青蛙跳台阶问题
 * @Date: 2021-12-08 17:00:09
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-08 17:30:16
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        int MOD = 1e9+7;
        int a = 1, b = 1, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (a + b) % MOD;
            a = b;
            b = sum;
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 7;
    cout << s.numWays(n) << endl;
    return 0;
}
