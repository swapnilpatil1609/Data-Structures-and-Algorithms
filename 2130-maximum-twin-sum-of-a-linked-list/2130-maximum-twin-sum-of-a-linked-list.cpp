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
 /*
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
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr!=NULL){
            ListNode* front = curr->next;
            curr->next = prev;
            prev=curr;
            curr=front;
        }
        ListNode* first = head;
        ListNode* second = prev;
        int sum,maxsum=0;
        while(second!=NULL){
            sum = first->val + second->val;
            first=first->next;
            second=second->next;
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};