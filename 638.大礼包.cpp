#include<vector>
#include<map>
#include<math.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
public:
    map<vector<int>, int> memo;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        // 过滤不需要计算的大礼包, 只保留需要计算的大礼包
        vector<vector<int>> filterSpcl;
        for (auto & sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpcl.push_back(sp);
            }
        }
        return dfs(price, special, needs, filterSpcl, n);
    }

    // 记忆化搜索计算满足购物清单所需花费的最低价格
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& curNeeds, vector<vector<int>>& filterSpcl, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; i++)
            {
                minPrice += curNeeds[i] * price[i]; //不购买大礼包，原价购买
            }
        
            for (auto & curSpcl : filterSpcl) {
                int specPrice = curSpcl[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; ++i) {
                    // 不能购买超出购物清单指定数量
                    if (curSpcl[i] > curNeeds[i]) {
                        break;
                    }
                    nxtNeeds.push_back(curNeeds[i] - curSpcl[i]);
                    // 大礼包可以购买
                    if (nxtNeeds.size() == n) {
                        minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpcl, n) + specPrice);
                    }
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};
// @lc code=end

