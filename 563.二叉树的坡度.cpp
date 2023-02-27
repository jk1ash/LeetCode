/*
 * @Author: jklash
 * @Description: 二叉树的坡度
 * @Date: 2021-11-18 09:34:04
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-18 10:09:59
 */
/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution {
public:
    int ans;

    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        ans += abs(l - r);
        return l + r + node->val;
    }
};
// @lc code=end

