class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* temp = head;
        int n = 1;
        while (temp->next != NULL) {
            n++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % n;
        int stepsToNewHead = n - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};
