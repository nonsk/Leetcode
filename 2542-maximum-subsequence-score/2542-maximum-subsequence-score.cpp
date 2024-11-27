class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> pairs(n);
        for(int i =0; i<n; i++){
            pairs[i] = {nums2[i], nums1[i]};
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, maxScore = 0;
        for(auto & [minNum, num]:pairs){
            sum+=num;
            minHeap.push(num);
            if(minHeap.size()>k){
                sum-=minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size()==k){
                maxScore = max(maxScore, sum*minNum);
            }
        }
        return maxScore;
    }
};