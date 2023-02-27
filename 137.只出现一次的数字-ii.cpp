/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/* 方法1: 哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int n : nums) {
            int count = m.count(n) + 1;
            m[n] = count++;
        }
        for (auto &t : m) {
            if (t.second == 1)
                ans = t.first;
        }
        return ans;
    }
};
*/
/* 方法2: 位运算 (有限状态自动机)*/
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int n : nums) {
            ones = ones ^ n & ~twos;
            twos = twos ^ n & ~ones;
        }
        return ones;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> test = {0,1,0,1,0,1,99};
    cout << s.singleNumber(test);
    cout << endl;
    return 0;
}
