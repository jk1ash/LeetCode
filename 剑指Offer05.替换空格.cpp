/*
 * @Author: jklash
 * @Description: 剑指 Offer 05. 替换空格
 * @Date: 2021-11-26 15:41:55
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-26 16:48:33
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size(), count = 0;
        for (auto c : s) {
            if (c == ' ')
                count++;
        }
        s.resize(n + 2 * count);
        for (int i = n - 1, j = s.size() - 1; i < j; --i, --j) {
            if (s[i] != ' ') {
                s[j] = s[i];
            }
            else {
                s[j- 2] = '%';
                s[j- 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string t = "We are happy.";
    cout << s.replaceSpace(t) << endl;
    return 0;
}
