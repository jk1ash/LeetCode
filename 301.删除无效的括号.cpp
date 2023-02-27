#include <vector>
#include <string>
#include <math.h>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
    int n;
    string s;
    vector <string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        //DFS回溯剪枝
        int l = 0, r = 0;
        this->s = s, this->n = s.size();
        for(char & c: s){
            if(c == '(') l++;
            else if(c == ')'){
                if(l == 0) r++;
                else l--;
            }
        }
        dfs(0, 0, l, r, "");
        return ans;
    }
    void dfs(int u, int lcnt, int l, int r, string path){
        if(u == n){
            if(lcnt == 0) ans.emplace_back(path);
            return;
        }
        if(s[u] == '('){
            int k = u + 1;
            while(k < n && s[k] == '(') k++;
            l -= k - u;
            for(int i = k - u; i >= 0; i--){
                if(l >= 0 && lcnt >= 0) dfs(k, lcnt, l, r, path); 
                path += '(', lcnt++, l++;         //左括号个数加一
            }
        }
        else if(s[u] == ')'){
            int k = u + 1;
            while(k < n && s[k] == ')') k++;
            r -= k - u;
            for(int i = k - u; i >= 0; i--){
                if(lcnt >= 0 && r >= 0) dfs(k, lcnt, l, r, path);
                path += ')', lcnt--, r++;
            }
        }
        else dfs(u + 1, lcnt, l, r, path + s[u]);
    }
};
// @lc code=end
