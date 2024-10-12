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
    bool isPalindrome(ListNode* head) {
        vector <int> ll;
        ListNode* run = head;
        while(run!=NULL){
            ll.push_back(run->val);
            run = run->next;
        }
        int last = ll.size()-1;
        int first =0;
        while(first<last){
            cout<<ll[first]<<" "<<ll[last]<<endl;
            if(ll[first]!=ll[last]){
                return false;
            }
            first++;
            last--;
        }
        // for(auto it:ll){
        //     cout<<it<<" ";
        // }
        return true;
    }
};