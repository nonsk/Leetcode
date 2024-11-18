class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string current = "";
        vector<string> yo;
        for (auto c : s) {
            if (c == ' ') {
                yo.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }
        if (current != "") {
            yo.push_back(current);
        }
        for (auto it : yo) {
            cout << it << endl;
        }
        unordered_set<char> st1;
        unordered_set<string> st2;
        for (auto c : pattern) {
            st1.insert(c);
        }
        for (auto c : yo) {
            st2.insert(c);
        }
        for (auto it : st1) {
            cout << it << endl;
        }
        for (auto it : st2) {
            cout << it << endl;
        }
        if (pattern.size() != yo.size()) {
            return false;
        }
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = yo[i];
            if (charToWord.find(c) != charToWord.end()) {
                if (charToWord[c] != word) {
                    return false;
                }
            } else {
                charToWord[c] = word;
            }
            if (wordToChar.find(word) != wordToChar.end()) {
                if (wordToChar[word] != c) {
                    return false;
                }
            } else {
                wordToChar[word] = c;
            }
        }
        return true;
    }
};
