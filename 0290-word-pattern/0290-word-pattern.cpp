class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split the string s into words using istringstream
        vector<string> words;
        string word;
        istringstream stream(s);
        while (stream >> word) {
            words.push_back(word);
        }

        // If the number of pattern characters doesn't match the number of words
        if (pattern.size() != words.size()) {
            return false;
        }

        // Maps to store the bijection between pattern characters and words
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (size_t i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];

            // Check mapping from character to word
            if (charToWord.find(c) != charToWord.end()) {
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                charToWord[c] = w;
            }

            // Check mapping from word to character
            if (wordToChar.find(w) != wordToChar.end()) {
                if (wordToChar[w] != c) {
                    return false;
                }
            } else {
                wordToChar[w] = c;
            }
        }

        // All mappings are consistent
        return true;
    }
};
