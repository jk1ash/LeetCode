/*
 * @Author: jklash
 * @Description: 重复叠加字符串匹配
 * @Date: 2021-12-22 14:57:48
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-27 15:14:52
 */
/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        int index = strStr(a, b);
        if (index == -1) 
            return -1;
        
        if (n - index >= m)
            return 1;
        
        return (m + index - n - 1) / n + 2;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        vector<int> next (m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) 
                j = next[j - 1];
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }

        for (int i = 0, j = 0; i - j < n; ++i) {
            while (j > 0 && haystack[i % n] != needle[j])
                j = next[j - 1];
            if (haystack[i % n] == needle[j])
                j++;
            if (j == m) 
                return i - m + 1; 
        }        
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string a = "abcd";
    string b = "cdabcdab";
    cout << s.repeatedStringMatch(a, b) << endl;
    return 0;
}
