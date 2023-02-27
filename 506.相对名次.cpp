/*
 * @Author: jklash
 * @Description: 相对名次
 * @Date: 2021-12-02 09:47:38
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-02 11:53:51
 */
/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<int, string> map;
    vector<string> medal {"Gold Medal", "Silver Medal", "Bronze Medal"};
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> temp = score;
        vector<string> ans;
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        for (int i = 0; i < n; ++i) {
            if (i < 3) {
                map[temp[i]] = medal[i];
            } else {
                map[temp[i]] = to_string(i + 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (map.count(score[i])) {
                ans.push_back(map.at(score[i]));
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> score {10,3,8,9,4};
    vector<string> ans = s.findRelativeRanks(score);
    for (auto a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" << endl;
    return 0;
}
