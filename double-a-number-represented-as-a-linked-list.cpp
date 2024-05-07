//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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
    ListNode* doubleIt(ListNode* head) {
        int ans=0;
        ListNode* rev =reverseList(head);

        int c=0;
        ListNode* current=rev , *previous=nullptr; 

        while(current != nullptr){
            int newValue = current->val*2 +c;
            current->val = newValue % 10;
            if(newValue >9) c=1;
            else
                c=0;
            previous =current ;
            current =current->next;
        }

            if(c != 0){
                ListNode* extraNode =new ListNode(c);
                previous->next = extraNode;
            }

            ListNode* result = reverseList(rev);

            return result;
    }

 ListNode* reverseList(ListNode* node){
    ListNode* previous= nullptr ,*current = node, *nextNode;

    while(current!= nullptr){
        nextNode=current->next;

        current->next=previous;
        previous =current;
        current = nextNode;
    }
    return previous;
 }
 };
