/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-08 11:18:14
 * @LastEditTime: 2021-11-08 11:50:43
 */
/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int a = 0, b = 0;
        vector<int> cnt1(10), cnt2(10);
        for (int i = 0; i < n; i++) {
            int c1 = secret[i] - '0', c2 = guess[i] - '0';
            if (c1 == c2) {
                a++;
            } else {
                cnt1[c1]++;
                cnt2[c2]++;
            }
        }
        for (int i =0; i < 10; i++) {
            b += min(cnt1[i], cnt2[i]);
        }
        return to_string(a) + 'A' + to_string(b) + 'B'; 
    }
};
// @lc code=end

