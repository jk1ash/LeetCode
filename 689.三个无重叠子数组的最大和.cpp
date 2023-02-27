/*
 * @Author: jklash
 * @Description: 三个无重叠子数组的最大和
 * @Date: 2021-12-08 11:36:08
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-08 15:34:56
 */
/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> sum (n + 1);
        
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<vector<long>> f (n + 10, vector<long> (4));
        
        for (int i = n - k + 1; i >= 1; --i) {
            for (int j = 1; j < 4; ++j) {
                f[i][j] = max(f[i + 1][j], f[i + k][j - 1]+ sum[i + k -1] - sum[i -1]);
            }
        }

        vector<int> ans (3);
        int i = 1, j = 3, idx = 0;
        while(j > 0) {
            if (f[i + 1][j] > f[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]) {
                i++;
            } else {
                ans[idx++] = i - 1;
                i += k;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {1,2,1,2,6,7,5,1};
    int k = 2;
    vector<int> ans;
    ans = s.maxSumOfThreeSubarrays(nums, k);
    cout << "[";
    for (auto& a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" << "]" << endl;
    return 0;
}

