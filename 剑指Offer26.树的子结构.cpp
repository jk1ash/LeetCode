/*
 * @Author: jklash
 * @Description: 剑指 Offer 26. 树的子结构
 * @Date: 2021-12-07 18:06:07
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-07 22:57:30
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr) 
                && (dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool dfs(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};