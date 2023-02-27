/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-02 15:02:53
 * @LastEditTime: 2021-11-02 15:43:38
 */
/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 将本节点的值改为下一个节点的值
        ListNode* next = node->next;
        node->next = node->next->next; // 删除下一个节点
        delete(next); // 释放下一个节点的指针
    }
};
// @lc code=end
