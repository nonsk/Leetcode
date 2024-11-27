class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
    vector<int> result;

    for (int spell : spells) {
        // Calculate the minimum potion strength needed for success
        long long threshold = (success + spell - 1) / spell; // Ceiling of success / spell

        // Use binary search to find the first potion meeting the threshold
        auto it = lower_bound(potions.begin(), potions.end(), threshold);

        // Count successful pairs for this spell
        result.push_back(potions.end() - it);
    }

    return result;
    }
};