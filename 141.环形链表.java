import java.util.HashMap;
import java.util.List;

import jdk.nashorn.internal.objects.annotations.Where;

/*
 * @lc app=leetcode.cn id=141 lang=java
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) 
            return false;
        
        Set<ListNode> set = new HashSet<ListNode>();
        while(head != null) {
            if (!set.add(head))
                return true;
            head = head.next;
        }
        return false;
    }
}
// @lc code=end

