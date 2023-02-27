/*
 * @Author: jklash
 * @Description: 剑指 Offer 24. 反转链表
 * @Date: 2021-11-22 21:43:15
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-22 22:28:03
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

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

    Solution s;
    ListNode *node = s.reverseList(head->next);
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}
