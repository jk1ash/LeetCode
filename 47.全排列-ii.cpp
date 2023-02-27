/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-28 14:55:51
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-12 14:12:49
 */
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end()); // 先将数组进行排列
        backtrace(ans, nums, path, 0, used, n); //回溯
        return ans;
    }

    void backtrace(vector<vector<int>>& ans, vector<int>& nums, vector<int>& path, int deepth, vector<bool>used, int size) {
        if (size == deepth) { //到底了, 进行剪枝
            ans.emplace_back(path);
            return ;
        }

        for (int i = 0; i < size; ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1]) && !used[i - 1]) // 1. 当前位置已被使用 2. 当前数字和前一个数字一样, 且前一个数字用过了
                continue;
            
            path.emplace_back(nums[i]);
            used[i] = true;
            backtrace(ans, nums, path, deepth + 1, used, size);
            used[i] = false;
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t = {3,3,0,3};
    vector<vector<int>> ret = s.permuteUnique(t);
    for (auto& it : ret) {
        for (auto& i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
