class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxCount = 0;
        int left = 0; 
        vector<int> freq(26, 0); 
        int maxLength = 0; 
        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'A']++; 
            maxCount = max(maxCount, freq[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--; 
                left++; 
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
