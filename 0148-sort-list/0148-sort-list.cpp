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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for(int i=0;i<ans.size();i++){
            temp->next = new ListNode(ans[i]);
            temp=temp->next;
        }
        return dummy->next;
    }
};