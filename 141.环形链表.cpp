// TODO 环形链表
/*
 * @Author: jklash
 * @Description: 环形链表
 * @Date: 2022-10-17 16:40:52
 * @LastEditTime: 2022-10-18 09:56:48
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *follow = NULL;
        while (head) {
            follow = head->next;
        }
        
    }
    bool hasCycle(ListNode *head) {
        
    }
};
// @lc code=end
