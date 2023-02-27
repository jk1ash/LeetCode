/*
 * @Author: jklash
 * @Description: 猫和老鼠
 * @Date: 2022-01-04 09:25:10
 * @LastEditors: jklash
 * @LastEditTime: 2022-01-04 10:53:03
 */
/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
const int N = 55;
class Solution {    
private:
    int f[2 * N * N][N][N];
    vector<vector<int>> graph;
    int n;
    
    int dfs(int k, int i, int j) {
        int ans = f[k][i][j];
        if (i == 0) {
            ans = 1;
        } else if (i == j) {
            ans = 2;
        } else if (k >= 2 * n * n) {
            ans = 0;
        } else if (ans == -1) {
            if (k % 2 == 0) {
                bool win = false, draw = false;
                for (auto& g : graph[i]) {
                    int t = dfs(k + 1, g, j);
                    if (t == 1) win = true;
                    else if (t == 0) draw = true;
                    if (win) break;
                }
                if (win) ans = 1;
                else if (draw) ans = 0;
                else ans = 2;
            } else {
                bool win = false, draw = false;
                for (auto& g : graph[j]) {
                    if (g == 0) continue;
                    int t = dfs(k + 1, i, g);
                    if (t == 2) win = true;
                    else if (t == 0) draw = true;
                    if (win) break;
                }
                if (win) ans = 2;
                else if (draw) ans = 0;
                else ans = 1;
            }
        }
        f[k][i][j] = ans;
        return ans;
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        this->graph = graph;
        this->n = graph.size();
        for (int k = 0; k < 2 * n * n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[k][i][j] = -1;
                }
            }
        }
        return dfs(0, 1, 2);
    }


};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> graph {{1,3},{0},{3},{0,2}};
    cout << s.catMouseGame(graph) << endl;
    return 0;
}
