class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto it : mp) {
            for (int i = 0; i < it.second.size(); i++) {
                for (int j = i+1; j < it.second.size(); j++) {
                    
                    if (abs(it.second[i] - it.second[j]) <= k) {
                        
                        return true;
                    }
                }
            }
        }
        return false;
    }
};