/*
 * @Author: jklash
 * @Description: 剑指 Offer 58 - II. 左旋转字符串
 * @Date: 2021-11-26 17:07:32
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-29 18:15:18
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void reverse(string& s, int left, int right) {
        while (left <= right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c; 
            left++;
            right--;
        }
    }
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size() - 1;
        reverse(s, 0, len); // gfedcba
        reverse(s, 0, len - n); // cdefgba
        reverse(s, len - n + 1, len); // cdefgab
        return s;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    string t = "abcdefg";
    int n = 6;
    cout << s.reverseLeftWords(t, n) << endl;
    return 0;
}

