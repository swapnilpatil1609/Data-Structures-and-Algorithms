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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        int eachBucketNode = l/k;
        int reaminderNode = l%k;

        vector<ListNode*> result(k,NULL);
        temp=head;
        for(int i=0;i<k;i++){
            result[i]=temp;
            for(int size=1;size<=eachBucketNode+(reaminderNode>0?1:0);size++){
                prev=temp;
                temp=temp->next;
            }
            if(prev!=NULL) prev->next=NULL;
            reaminderNode--;
        }
        return result;
    }
};