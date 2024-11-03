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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        ListNode* stop = last;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
        while (prev != stop) {
            cout<<"done"<<endl;
            last->next = curr;
            curr->next = NULL;
            prev->next = nxt;
            last = curr;
            prev = nxt;
            if (nxt->next == NULL)
                break;
            curr = nxt->next;
            if (curr->next == NULL)
                break;
            nxt = curr->next;
            ListNode* it = head;
            // while (it != NULL) {
            //     cout << it->val << " ";
            //     it = it->next;
            // }
            // cout << endl;
        }
        return head;
    }
};