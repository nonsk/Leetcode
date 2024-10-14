class Solution {
public:
    // Optimized Helper Function: Returns true if we can make m bouquets within mid days.
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int mid) {
        int flowers = 0, bouquets = 0;

        // Early stopping if bouquets already exceed or meet the required count.
        for (int day : bloomDay) {
            if (day <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;  // Reset flower count for the next bouquet
                    if (bouquets >= m) return true;  // Early stop if enough bouquets are made
                }
            } else {
                flowers = 0;  // Reset flowers if day exceeds the current mid
            }
        }
        return false;  // Not enough bouquets made within mid days
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // If there aren't enough flowers to make m bouquets, return -1
        if (static_cast<long long>(m) * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search to find the minimum number of days
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;  // Search for fewer days
            } else {
                low = mid + 1;  // Increase the days
            }
        }
        return low;
    }
};
