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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        int i=0;
        int j=n-1;
        int maxsum = 0;
        int sum;
        while(i<j){
            sum = ans[i]+ans[j];
            i++;
            j--;
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};