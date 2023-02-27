/*
 * @Author: jklash
 * @Description: 剑指 Offer 63. 股票的最大利润
 * @Date: 2021-12-08 17:45:36
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-08 22:05:00
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT32_MAX, ans = 0;
        for (auto& price : prices) {
            cost = min(cost, price);
            ans = max(ans, price - cost);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {7,1,5,3,6,4};
    cout << s.maxProfit(nums) << endl;
    return 0;
}
