//https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1561368385/
//very imp 
//hard
//look again through the loops

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0, head);
        ListNode* groupprev = ans;

        while (true) {
            ListNode* kth = getKth(groupprev, k);
            if (!kth) 
                break;
            
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupprev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* tmp = groupprev->next;
            groupprev->next = kth;
            groupprev = tmp;
        }

        return ans->next;
    }

private:
    ListNode* getKth(ListNode* a, int k) {  
        while (a && k > 0) {
            k--;
            a = a->next;
        }
        return a;
    }
};