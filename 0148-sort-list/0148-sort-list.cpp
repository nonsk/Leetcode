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
        vector<int> ll;
        ListNode* temp = head;
        while(temp!=NULL){
            ll.push_back(temp->val);
            temp = temp->next;
        }
        for(auto it :ll){
            cout<<it<<" ";
        }
        sort(ll.begin(), ll.end());
        temp = head;
        for(auto it :ll){
            temp->val = it;
            temp = temp->next;
        }
        return head;

    }
};