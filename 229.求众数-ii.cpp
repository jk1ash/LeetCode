#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        int c1 = nums[0], count1 = 0;
        int c2 = nums[0], count2 = 0;

        for (int num : nums) {
            if (c1 == num) count1++;
            else if (c2 == num) count2++;
            else if (count1 == 0) {
                c1 = num;
                count1++;
            }
            else if (count2 == 0) {
                c2 = num;
                count2++;
            } 
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (c1 == num) count1++;
            else if (c2 == num) count2++;
        }

        if (count1 > (n / 3)) ans.push_back(c1);
        if (count2 > (n / 3)) ans.push_back(c2);

        return ans;    
    }
};
// @lc code=end

