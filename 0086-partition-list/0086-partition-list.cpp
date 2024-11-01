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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* lstart = less;
        ListNode* more = new ListNode(0);
        ListNode* mstart = more;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val>=x){
                ListNode* add = new ListNode(temp->val);
                more->next = add;
                more = more->next;
            }
            else{
                ListNode* add = new ListNode(temp->val);
                less->next = add;
                less = less->next;
            }
            temp = temp->next;
        }
        less->next = mstart->next;
        temp = lstart;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
        temp = mstart;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        return lstart->next;
    }
};