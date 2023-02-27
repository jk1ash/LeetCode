/*
 * @Author: jklash
 * @Description: 最短补全词
 * @Date: 2021-12-10 09:39:38
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-10 10:43:43
 */
/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // 对licensePlate词频统计 
        vector<int> cnt(26, 0);
        int type = 0;
        for (auto& c : licensePlate) {
            if (isalpha(c))
                if (++cnt[tolower(c) - 'a'] == 1)
                    type++;
        }
        
        string ans {""};

        // 对words词频统计
        for (auto& word : words) {
            vector<int> cur(cnt);
            int temp = type;
            for (auto& w : word) {
                if (--cur[w - 'a'] == 0)
                    temp--;
            }
            if (temp == 0 && (ans.size() == 0 || ans.size() > word.size()))
                ans = word;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string l = "1s3 PSt";
    vector<string> w {"step", "steps", "stripe", "stepple"};
    cout << s.shortestCompletingWord(l, w) << endl;    
    return 0;
}
