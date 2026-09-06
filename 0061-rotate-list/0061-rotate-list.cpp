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
    ListNode* findNode(ListNode* head,int k){
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next!=NULL){
            len++;
            tail = tail->next;
        }
        if(len==k || k==0) return head;
        k = k%len;
        tail->next=head;
        ListNode* n = findNode(head,len-k-1);
        head=n->next;
        n->next=NULL;
        return head;
    }
};