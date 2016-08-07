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
        ListNode * pre = NULL;
        ListNode * next = NULL;
        while(head != NULL)
        {
            next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL)
    //         return head;
    //     if(head -> next == NULL)
    //         return head;
    //     ListNode * post = head -> next;
    //     head -> next = NULL;
    //     ListNode * newHead = reverseList(post);
    //     post -> next = head;
    //     return newHead;
    // }
};