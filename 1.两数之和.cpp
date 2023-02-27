/*
 * @Author: jklash
 * @Description: 两数之和
 * @Date: 2021-11-25 16:50:59
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-25 17:16:10
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(target - nums[i])) {
                return {map.at(target - nums[i]), i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> t {2,7,11,15};
    int target = 9;
    Solution s;
    for (auto i : s.twoSum(t, target))
        cout << i << ",";
    cout << "\b \b" << endl;
    return 0;
}
