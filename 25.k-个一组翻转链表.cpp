/*
 * @Author: jklash
 * @Description: K 个一组翻转链表
 * @Date: 2021-11-22 19:31:10
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-30 14:05:43
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
private:
    // 反转链表
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
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

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 设置虚拟节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* end = dummy;

        while (end->next != nullptr) {
            // 将end的节点定位到k处
            for (int i = 0; i < k && end != nullptr; ++i) 
                end = end->next;
            
            // end为空时, 需要反转的节点数小于k, 不进行反转, 退出
            if (end == nullptr)
                break;

            ListNode* start = pre->next;
            ListNode* temp = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = temp;
            pre = start;

            end = pre;
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
    int k = 3;
    ListNode *node = s.reverseKGroup(head->next, 3);
    while (node != nullptr) {
        cout << node->val << ",";
        node = node->next;
    }
    cout << "\b \b" << endl;
    return 0;
}
