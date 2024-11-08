class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;
        
        // Initialize two priority queues, one for the first part and one for the last part of the list
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> first;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> last;

        int left = 0;           // Pointer for the start of the list
        int right = n - 1;      // Pointer for the end of the list

        // Populate both priority queues initially with candidates
        for (int i = 0; i < candidates && left <= right; i++, left++) {
            first.push({costs[left], left});
        }
        for (int i = 0; i < candidates && left <= right; i++, right--) {
            last.push({costs[right], right});
        }

        // Process the minimum costs for k elements
        for (int i = 0; i < k; i++) {
            if (!last.empty() && (first.empty() || last.top().first < first.top().first)) {
                // Choose from the 'last' queue if it's smaller
                ans += last.top().first;
                int idx = last.top().second;
                last.pop();

                if (left <= right) { // Add new element from the left side to 'last' queue if available
                    last.push({costs[right], right});
                    right--;
                }
            } else {
                // Choose from the 'first' queue if it's smaller
                ans += first.top().first;
                int idx = first.top().second;
                first.pop();

                if (left <= right) { // Add new element from the right side to 'first' queue if available
                    first.push({costs[left], left});
                    left++;
                }
            }
        }

        return ans;
    }
};
