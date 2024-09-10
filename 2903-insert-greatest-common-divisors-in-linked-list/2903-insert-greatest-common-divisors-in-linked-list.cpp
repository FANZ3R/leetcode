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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* old_head= head;
        
        while(head!=NULL && head->next!=NULL)
        {

            int t= __gcd(head->val,head->next->val);

            ListNode* temp = new ListNode(t);

            ListNode* nex= head->next;

            head->next=temp;
            temp->next=nex;
            head=nex;
        }
        

        return old_head;
    }
};