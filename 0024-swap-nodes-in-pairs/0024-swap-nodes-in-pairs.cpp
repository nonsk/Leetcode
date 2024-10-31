class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;  
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current && current->next) {
            ListNode* nextPair = current->next->next;  
            ListNode* second = current->next; 
            second->next = current;
            current->next = nextPair;
            if (prev) {
                prev->next = second;  
            }
            prev = current;
            current = nextPair;
        }
        return newHead;
    }
};
