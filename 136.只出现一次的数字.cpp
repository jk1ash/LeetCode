/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-30 11:09:23
 * @LastEditTime: 2021-10-30 17:06:01
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

/* 方法1: 异或 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            ans ^= num;
        }
        return ans;
    }
}; 
*/
/* 方法2: 哈希表 */
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> map;
        for (int num : nums) {
            int count = map.count(num) + 1;
            map[num] = count++;
        }

        for (auto &t : map) {
            if (t.second == 1)
                ans = t.first;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> test = {2,2,1,1,9};
    cout << s.singleNumber(test);
    cout << endl;
    return 0;
}
