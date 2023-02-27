/*
 * @Author: jklash
 * @Description: 打乱数组
 * @Date: 2021-11-22 10:43:50
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-22 14:24:01
 */
/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> save;
    vector<int> sh;
public:
    Solution(vector<int>& nums) {
        save = nums;
        sh = nums;
    }
    
    vector<int> reset() {
        return save;
    }
    
    vector<int> shuffle() {
        int n = sh.size();
        for (int i = 0; i < n; ++i) {
            // KnuthKnuth 洗牌算法
            int j = i + rand() % (n - i);
            swap(sh[i], sh[j]);
        }
        return sh;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> t = {1, 2, 3};
    Solution s(t);
    for (auto r : s.reset()) {
        cout << r << " ";
    }
    cout << endl;
    for (auto sh : s.shuffle()) {
        cout << sh << " ";
    }
    cout << endl;
    return 0;
}
