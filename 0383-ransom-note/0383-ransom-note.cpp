class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create a frequency table for the magazine characters
        vector<int> freq(26, 0); // Since there are only lowercase English letters
        
        // Count frequency of each character in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }
        
        // Check if ransomNote can be constructed from magazine
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) {
                return false; // Not enough characters available
            }
            freq[c - 'a']--; // Use the character
        }
        
        return true;
    }
};
