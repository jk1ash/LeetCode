/*
 * @Author: jklash
 * @Description: 剑指 Offer 32 - II. 从上到下打印二叉树 II
 * @Date: 2021-12-07 17:01:26
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-07 17:20:12
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp(n);
            for(int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
            ans.push_back(tmp);
        }
        return ans; 
    }
};