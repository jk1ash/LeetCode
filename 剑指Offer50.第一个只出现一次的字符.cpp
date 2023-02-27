/*
 * @Author: jklash
 * @Description: 剑指 Offer 50. 第一个只出现一次的字符
 * @Date: 2021-12-06 22:43:08
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 22:53:52
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, int> map;
public:
    char firstUniqChar(string s) {
        for (auto& c : s) {
            map[c]++;
        }
        for (auto& c : s) {
            if (map.at(c) == 1) {
                return c;
            }
        }
        return ' ';
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abaccdeff";
    cout << s.firstUniqChar(str) << endl;
    return 0;
}
