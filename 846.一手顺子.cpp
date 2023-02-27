/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        // 如果不能完整分组，返回错误
        if (n % groupSize != 0) return false;
        // 排序
        sort(hand.begin(), hand.end());
        
        unordered_map<int, int> map;
        // 存入hash表
        for (auto& h : hand) {
            map[h]++;
        }
        
        for (auto& h : hand) {
            if (!map.count(h)) {
                continue;
            }

            // 判断是否顺子
            for (int i = 0; i < groupSize; ++i) {
                int num = h + i;
                // 不是顺子， 返回错误
                if (!map.count(num)) {
                    return false;
                }
                // 出队
                map[num]--;
                if (map[num] == 0) {
                    map.erase(num);
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> hand {1,2,3,6,2,3,4,7,8};
    int size = 3;
    cout << s.isNStraightHand(hand, size) << endl;
    return 0;
}
