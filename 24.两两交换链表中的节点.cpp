/*
 * @Author: jklash
 * @Description: 两两交换链表中的节点
 * @Date: 2021-11-30 10:41:19
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-30 11:45:32
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    方法1：递归
 */
#if 0
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 当节点用完或者只剩一个节点时，返回
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp = head->next; // 设置节点指向下一个节点
        head->next = swapPairs(temp->next); // 递归处理每两个节点
        temp->next = head; // 设置节点的下一个节点指向上一个节点, 进行交换
        return temp;
    }
};
#endif
/* 
    方法2：迭代
 */
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) { 
        // 定义虚拟头节点 
        ListNode* dummy = new ListNode(0);
        // 指向头节点
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            // a前进一步，b前进两步
            ListNode* a = temp->next;
            ListNode* b = temp->next->next;
            // 通过temp交换节点
            temp->next = b;
            a->next = b->next;
            b->next = a;
            // 前进
            temp = a;
            b = a;
        }
        return dummy->next;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> nums {1,2,3,4,5};
    ListNode* head = new ListNode(0);
    ListNode* list = head;
    
    for (auto n : nums) {
        ListNode* node = new ListNode(n);
        list->next = node;
        list = node;
    }
    list->next = nullptr;
    
    ListNode* print = head->next;
    while (print!= nullptr) {
        cout << print->val << ",";
        print = print->next;
    }
    cout << "\b \b" << endl;

    Solution s;
    ListNode *node = s.swapPairs(head->next);
    while (node != nullptr) {
        cout << node->val << ",";
        node = node->next;
    }
    cout << "\b \b" << endl;
 
    return 0;
}
