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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* prev = NULL;
        while(mid!=NULL){
            ListNode* front = mid->next;
            mid->next = prev;
            prev=mid;
            mid=front;
        }
        ListNode* rev = prev;
        ListNode* curr = head;
        while(rev->next!=NULL){
            ListNode* temp = curr->next;
            curr->next=rev;
            ListNode* temprev = rev->next;
            rev->next = temp;
            curr=temp;
            rev=temprev;
        }
    }
};