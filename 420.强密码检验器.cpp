/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int A = 0, B = 0, C = 0;
        for (char c : password) {
            if (c >= 'a' && c < 'z') A = 1;
            else if (c >= '0' && c <= '9') B = 1;
            else if (c >= 'A' && c <= 'Z') C = 1;
        }
        int m = A + B + C;
        if (n < 6) {
            return max(6 - n, 3 - m);
        } else if (n <= 20) {
            int tot = 0;
            for (int i = 0; i < n;) {
                int j = i;
                while(j < n && password[j] == password[i]) j++;
                int cnt = j - i;
                if (cnt >= 3) tot += cnt / 3;
                i = j;
            }
            return max(tot, 3 - m);
        } else {
            int tot = 0;
            vector<int> cnts = vector<int>(3);
            for (int i = 0; i < n;) {
                int j = i;
                while (j < n && password[j] == password[i]) j++;
                int cnt = j - i;
                if (cnt >= 3) {
                    tot += cnt / 3;
                    cnts[cnt % 3]++;
                }
                i = j;
            }
            int base = n - 20, cur = base;
            for (int i = 0; i < 3; ++i) {
                if (i == 2) cnts[i] = tot;
                if (cnts[i] != 0 && cur !=0) {
                    int t = min(cnts[i] * (i + 1), cur);
                    cur -= t;
                    tot -= t / (i + 1);
                }
            }
            return base + max(tot, 3 - m);
        }
    }
};
// @lc code=end

