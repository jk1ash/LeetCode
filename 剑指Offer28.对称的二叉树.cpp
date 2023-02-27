/*
 * @Author: jklash
 * @Description: 剑指 Offer 28. 对称的二叉树
 * @Date: 2021-12-07 23:11:09
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-07 23:20:41
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* L, TreeNode* R) {
        if (L == nullptr && R == nullptr) 
            return true;
        
        if (L == nullptr || R == nullptr || L->val != R->val) 
            return false;

        return isMirror(L->left, R->right) && isMirror(L->right, R->left);
    }
};
