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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * ret = new ListNode(0);
        ret -> next = head;
        ListNode * pre = ret;
        while(head != NULL) {
            while(head != NULL && head -> val == val) {
                pre -> next = head -> next;
                head = pre -> next;
            }
            if(head == NULL)
                break;
            head = head -> next;
            pre = pre -> next;
        }
        return ret -> next;
    }
};