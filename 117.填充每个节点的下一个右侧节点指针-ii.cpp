#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        /* 层序遍历 */
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            // 每一层的节点数量
            int n = q.size();
            // 前一个节点
            Node* pre = nullptr;
            for (int i = 1; i <= n; ++i) {
                // 遍历取出节点
                Node* cur = q.front();
                q.pop();
                
                
                if (cur->left) { // 左节点加入队列
                    q.push(cur->left);
                }
                if (cur->right) { // 右节点加入队列
                    q.push(cur->right);
                }

                // 如果pre为空，说明为第一个节点, 没有前一个节点 */
                if (pre) {
                    pre->next = cur;
                } 
                pre = cur; //当前节点成为下一个节点
            }
        }
        return root;  
    }
};
// @lc code=end

