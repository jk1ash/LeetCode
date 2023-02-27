/*
 * @Author: jklash
 * @Description: 随机翻转矩阵
 * @Date: 2021-11-29 10:24:34
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-29 11:25:17
 */
/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int x = random() % total--; 
        vector<int> ans;
        // 查找位置x对应的映射
        if (map.count(x)) {
            ans = {map[x] / n, map[x] % n};
        } else {
            ans = {x / n, x % n};
        }
        // 将位置x对应的映射设置为位置total对应的映射
        if(map.count(total)) {
            map[x] = map[total];
        } else {
            map[x] = total;
        }
        return ans;
    }
    
    void reset() {
        total = m * n;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end

void vector_print(vector<int>& ans) {
    for (auto a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" <<endl;
}

int main(int argc, char const *argv[])
{
    int m = 3;
    int n = 1;
    vector<int> ans;
    Solution s(m, n);
    ans = s.flip();
    ans = s.flip();
    ans = s.flip();
    s.reset();
    ans = s.flip();
    return 0;
}
