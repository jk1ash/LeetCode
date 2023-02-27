/*
 * @Author: jklash
 * @Description: 在线选举
 * @Date: 2021-12-11 12:02:53
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-12 11:43:15
 */
/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// @lc code=start
class TopVotedCandidate {
private:
    vector<int> tops, times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> map;
        map[-1] =  -1;
        int top = -1;
        for (auto& p : persons) {
            map[p]++;
            if (map[p] >= map[top]) {
                top = p;
            }
            tops.emplace_back(top);
        }
        this->times = times;
    }
    
    int q(int t) {
        int l = 0, r = times.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (times[m] <= t) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return tops[l];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> p{0, 1, 1, 0, 0, 1, 0} ,t{0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate top (p, t);
    cout << top.q(3) << endl;
    cout << top.q(12) << endl;
    cout << top.q(25) << endl;
    cout << top.q(15) << endl;
    cout << top.q(24) << endl;
    cout << top.q(8) << endl;
    return 0;
}
