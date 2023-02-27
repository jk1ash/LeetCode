/*
 * @Author: jklash
 * @Description:  最长重复子串
 * @Date: 2021-12-23 09:35:58
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-30 17:38:00
 */
/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int n;
    unsigned long long prime = 31;
    string longestDupSubstring(string s) {
        n = s.size();
        int left = 1;
        int right = n - 1;
        int pos = -1;
        int len = 0;

        auto find = [&](int len) {
            unsigned long long hash = 0;
            unsigned long long power = 1;
            for (int i = 0; i < len; ++i) {
                hash = hash * prime + (s[i] - 'a');
                power *= prime;
            }
            unordered_set<unsigned long long> exist(hash);
            for (int i = len; i < n; ++i) {
                hash = hash * prime - power * (s[i - len] - 'a') + (s[i] - 'a');
                if (exist.count(hash))
                    return (i - len + 1);
                exist.insert(hash);
            }
            return -1;
        };

        while (left <= right) {
            int mid = left + (right -left) / 2;
            int start = find(mid);
            if (start != -1) {
                len = mid;
                pos = start;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (pos == -1)
            return "";
        else
            return s.substr(pos, len);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "aa";
    cout << s.longestDupSubstring(str) << endl;
    return 0;
}
