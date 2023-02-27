/*
 * @Author: jklash
 * @Description: 剑指 Offer 06. 从尾到头打印链表
 * @Date: 2021-11-22 15:38:45
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-22 19:59:12
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        ListNode *node = head;
        while (node != nullptr) {
            stk.push(node->val);
            node = node->next;
        }
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* 头插法 */
    vector<int> nums {1,2,3,4};
    ListNode* head = nullptr;
    for (auto n : nums) {
        ListNode* node = new ListNode(n);
        node->next = head;
        head = node;
    }
    
    /* 尾插法 */
    ListNode* rear = new ListNode(0);
    ListNode* list = rear;
    for (auto n : nums) {
        ListNode* node = new ListNode(n);
        list->next = node;
        list = node;
    }
    list->next = nullptr;

    Solution s; 
    vector<int> ret = s.reversePrint(rear->next);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
