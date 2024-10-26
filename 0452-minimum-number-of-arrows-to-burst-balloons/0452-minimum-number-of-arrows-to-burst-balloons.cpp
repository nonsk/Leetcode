class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int last = points[0][1]; 
        int ans = 1; 
        for(const auto& it : points) {
            if(it[0] > last) {
                ans++;
                last = it[1]; 
                std::cout << last << std::endl;
            }
        }
        return ans;
    }
};
