/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */

#include "TreeNode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
    int dfs(TreeNode *root, int cur)
    {
        int ans = 0, ncur = (cur << 1) + root->val;
        if (root->left)
            ans += dfs(root->left, ncur);
        if (root->right)
            ans += dfs(root->right, ncur);
        return root->left == nullptr && root->right == nullptr ? ncur : ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> val {1,0,1,0,1,0,1};
    TreeNode* root = CreatTree(val);
    PrintTree(root);
    cout << "ans:" << s.sumRootToLeaf(root) << endl;
    return 0;
}
