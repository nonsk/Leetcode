#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        
        // Initial setup
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // Check if the current string is valid
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }
            
            // Stop further exploration if a valid expression is found at this level
            if (found) continue;

            // Generate all possible states by removing one parenthesis
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);
                
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        
        return result;
    }

private:
    // Function to check if a string is a valid expression
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }
};
