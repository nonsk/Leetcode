class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map <int, vector<int>>mp;
        for(int i =0; i<edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int n=mp.size();
        int ans = -1;
        for(auto it:mp){
           if(it.second.size()==n-1){
            return it.first;
           }
        }
        return -1;
    }
};