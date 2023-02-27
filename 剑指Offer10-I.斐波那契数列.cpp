/*
 * @Author: jklash
 * @Description: 剑指 Offer 10- I. 斐波那契数列
 * @Date: 2021-12-08 15:37:40
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-08 17:08:30
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int MOD = 1e9+7; // 大数取余, 防止溢出
        int a = 0, b = 1, sum = 0;
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
    cout << s.fib(n) << endl;
    return 0;
}
