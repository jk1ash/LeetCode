/*
 * @Author: jklash
 * @Description: 剑指 Offer 32 - I. 从上到下打印二叉树
 * @Date: 2021-12-07 16:09:08
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-07 16:50:03
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);
                if (t->left != nullptr) {
                    q.push(t->left);
                }
                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }
        }
        return ans;
    }
};