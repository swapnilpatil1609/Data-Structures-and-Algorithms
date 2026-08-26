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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int result = 0;
        int power = 0;
        while(head!=NULL){
            if(head->val==1){
                result+=pow(2,power);
            }
            power++;
            head=head->next;
        }
        return result;
    }
};