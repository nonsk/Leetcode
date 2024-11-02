
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* last = head;
        vector<int> list;
        while(last!=NULL){
            list.push_back(last->val);
            last = last->next;
        }
        for(auto it: list){
            cout<<it<<" ";
        }
        cout<<endl;
        int n = list.size();
        int ans = INT_MIN;
        for(int i =0; i<n/2; i++){
            cout<<list[i]<<endl;
            cout<<list[n-1-i]<<endl<<endl;
            ans = max(ans, list[n-1-i]+list[i]);
        }
        return ans;
    }
};