//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/?envType=daily-question&envId=2025-02-24

//can be done by counting or iterating with 2 lists

//medium 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n==1)
            return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        int count=0;
        while(slow){
            slow=slow->next;
            count++;
        }
        if(n==count)
            return head->next;
        n=count-n;
        slow=head;
        while(n--){
            slow=fast;
            fast=fast->next;
        }
        slow->next=fast->next;
        free(fast);
        return head;
    }
};
