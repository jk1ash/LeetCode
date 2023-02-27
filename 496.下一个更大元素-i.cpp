#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> map;
        vector<int> ans(m);
        stack<int> stk;
        /* 遍历nums2，将每个数字的下一个更大元素找出，存入hashmap里 */
        for (int i = n - 1; i >= 0; --i) {
            int num = nums2[i];
            // 将比当前元素小的元素出栈
            while(!stk.empty() && num >= stk.top()) {
                stk.pop();
            }
            // 将下一个更大元素存入存入hashmap，找不到则存入-1
            map[num] = stk.empty() ? -1 : stk.top(); 
            stk.push(num);
        }
        // 从hashmap中找到对应数字的下一个更大元素
        for (int i = 0; i < m; ++i) {
            ans[i] = map[nums1[i]];
        }
        return ans;
    }
};
// @lc code=end

