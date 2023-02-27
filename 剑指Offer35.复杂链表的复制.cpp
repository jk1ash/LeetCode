/*
 * @Author: jklash
 * @Description: 剑指 Offer 35. 复杂链表的复制
 * @Date: 2021-11-22 22:28:57
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-25 17:59:46
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (!map.count(head)) {
            Node* newHaed = new Node(head->val);
            map[head] = newHaed;
            newHaed->next = copyRandomList(head->next);
            newHaed->random = copyRandomList(head->random);
        }
        return map[head];
    }
};
