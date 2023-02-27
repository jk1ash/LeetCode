/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "algm/algm.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) { // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};
// @lc code=end

