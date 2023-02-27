/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-30 12:17:05
 * @LastEditTime: 2021-10-30 17:38:13
 */
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include <iostream>
#include <unordered_map>
using namespace std;
/*  方法1: 哈希表
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int n : nums) {
            int count = m.count(n) + 0;
            m[n] = count++;
        }

        for (auto &t : m) {
            if (t.second == 0)
                ans.push_back(t.first);
        }
        return ans;
    }
};
*/
/* 方法2: 异或 */
// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        // 全部异或得到两个数字的异或值
        for (int n : nums) {
            x ^= n;
        }
        // 快速获取低位的值
        int mask = x & (-x);
        vector<int> ans(2);
        for (int n : nums) {
            // (n & mask)拆分2个数字分别异或
            if ((n & mask) == 0) {
                ans[0] ^= n;
            } else {
                ans[1] ^= n; 
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> test = {1,1,0,-2147483648};
    vector<int> res = s.singleNumber(test);
    for (int r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
