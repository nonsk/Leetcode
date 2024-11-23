class Solution {
public:
    static bool srt(pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it] = 0;
        }
        for (auto it : nums) {
            mp[it]++;
        }
        vector<pair<int,int>> ans;
        for (auto it : mp) {
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end(), srt);
        for (auto it : mp) {
            cout << it.first << " ";
        }
        cout << endl;
        for (auto it : mp) {
            cout << it.second << " ";
        }
        cout<<endl;
        for (auto it : ans) {
            cout << it.first << " ";
        }
        cout << endl;
        for (auto it : ans) {
            cout << it.second << " ";
        }

        vector<int> ans2;

        for(int i=0; i<k; i++){
            ans2.push_back(ans[i].first);
        }
        return ans2;
    }
};