/*
 * @Author: jklash
 * @Description: N 叉树的最大深度
 * @Date: 2021-11-21 10:58:30
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-21 11:02:41
 */
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        for (auto node : root->children) {
            ans = max(ans, maxDepth(node));
        }
        return ans + 1;
    }
};
// @lc code=end

