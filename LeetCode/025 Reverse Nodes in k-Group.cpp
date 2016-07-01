//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode *ptr=head, *dummy = new ListNode(INT_MIN);
        while(ptr){
            ++cnt;
            ptr=ptr->next;
        }
        if(cnt<k || k<=1 || !head) return head;
        dummy->next = head;
        ptr=dummy;
        cnt = cnt/k;
        while(cnt--){
                ptr=change(ptr,k);
            }
        head = dummy->next;
        delete dummy;
        return head;
    }
    ListNode* change(ListNode* left, int k){
        ListNode *ptr=left->next, *tail=left->next, *head=left;
        while(k--){
            ListNode *temp = ptr->next;
            ptr->next=left;
            left=ptr;
            ptr=temp;
        }
        head->next=left;
        tail->next=ptr;
        return tail;
    }
};