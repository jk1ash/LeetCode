/*
 * @lc app=leetcode.cn id=547 lang=java
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int len = isConnected.length;
        boolean[] visited = new boolean[len];
        int count = 0;
        for (int i = 0; i < len; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }

    public void dfs(int[][] isConnected, boolean[] visited, int i) {
        visited[i] = true;        
        for (int j = 0; j < isConnected[0].length; j++) {
            if(isConnected[i][j] == 1 && !visited[j])
                dfs(isConnected, visited, j);
        }
    }
}
// @lc code=end

