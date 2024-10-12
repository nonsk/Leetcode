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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        cout << size << endl;
        temp = head;
        ListNode* prev = temp;
        if (size == 1 && n == 1) {
            return NULL;
        }
        while (temp != NULL) {
            cout << temp->val << endl;
            cout << "now " << count << " " << size - n - 1 << endl;
            if (count >= size - n - 1) {
                if(count > size - n - 1){
                    cout<<"val"<<prev->val;
                    // prev =  prev->next;
                    return prev->next;
                }
                ListNode* temp2 = temp;
                if (temp2->next == NULL) {
                    temp = NULL;
                    return head;
                }
                temp2 = (temp2->next)->next;
                temp->next = temp2;
                return head;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};