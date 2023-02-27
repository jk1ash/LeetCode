#include<vector>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size(),
            n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res ++;
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<char>>& nums, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            if (row < 0 || col < 0 || row >= nums.size() || col >= nums[0].size() || nums[row][col] == '0') 
                continue;
            
            nums[row][col] = '0';
            q.push(make_pair(row + 1, col));
            q.push(make_pair(row, col + 1));
            q.push(make_pair(row, col - 1));
            q.push(make_pair(row - 1, col));

        }
    }
};
// @lc code=end