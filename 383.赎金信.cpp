/*
 * @Author: jklash
 * @Description: 赎金信
 * @Date: 2021-12-04 10:10:17
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-04 10:41:00
 */
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        vector<int> cnt(26);
        for (auto& c : magazine) {
            cnt[c - 'a']++;
        }

        for (auto& c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string note = "oooo", mgz = "asdnlasokdocxmiouio";
    cout << s.canConstruct(note, mgz) << endl;
    return 0;
}
