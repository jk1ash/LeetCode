/*
 * @Author: jklash
 * @Description: 找到字符串中所有字母异位词
 * @Date: 2021-11-28 12:24:32
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-29 10:14:18
 */
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans {};
        if (n < m) return ans;
        vector<int> scnt(26), pcnt(26);
        // p字母计数
        for (int i = 0; i < m; ++i) {
            pcnt[p[i] - 'a']++;
        }
        int left = 0;
        for (int right = 0; right < n; ++right) {
            // s字母计数
            int curRight = s[right] - 'a';
            scnt[curRight]++;
            // 如果当前字母在s比p多，则窗口滑动
            while (scnt[curRight] > pcnt[curRight]) {
                int curLeft = s[left] - 'a';
                // 当前字母去除 
                scnt[curLeft]--;
                left++;
            }
            // 如果当前滑动窗口的长度等于p的长度，添加到结果中
            if (right - left + 1 == m) ans.push_back(left);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ans {};
    string a = "abab";
    string b = "ab";
    ans = s.findAnagrams(a, b);
    for (auto a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" << endl;
    return 0;
}
