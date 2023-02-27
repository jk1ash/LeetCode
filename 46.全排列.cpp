/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-28 22:45:48
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-10 18:27:03
 */
#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    
    vector<int> path;
    vector<vector<int>> ans;

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            int size = nums.size();
            vector<bool> used (size, false);
            dfs(nums, 0, used, size);
            return ans;
        }
        void dfs (vector<int>& nums, int deepth, vector<bool> used, int size) {
            if (size == deepth) { // 到底了进行剪枝, 将该路径加入到答案
                ans.emplace_back(path);
                return ;
            }

            for (int i = 0; i < size; ++i) {
                if (used[i]) {
                    continue;
                }

                path.emplace_back(nums[i]);
                used[i] = true;
                dfs(nums, deepth + 1, used, size); // 按顺序进行dfs
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
    vector<int> test = {1, 2, 3};
    vector<vector<int>> ret = s.permute(test);
    for (auto& it : ret) {
        for (auto& i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


