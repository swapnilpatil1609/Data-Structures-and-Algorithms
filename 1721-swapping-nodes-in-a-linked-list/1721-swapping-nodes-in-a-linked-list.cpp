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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        int originalK = k;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        ListNode* first = head;
        while(k>1){
            first=first->next;
            k--;
        }
        int k2=cnt-originalK+1;
        ListNode* last = head;
        while(k2>1){
            last=last->next;
            k2--;
        }
        swap(first->val,last->val);
        return head;
    }
};