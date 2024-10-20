class Solution {
public:
    void func(int n, int k, set<int> &index, string &answer) {
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; 
        if (n == 1) {
            answer += to_string(*index.begin());
            return;
        }
        int front = (k - 1) / fact[n - 1];
        auto it = index.begin();
        advance(it, front); 
        answer += to_string(*it);
        index.erase(it);
        func(n - 1, k - front * fact[n - 1], index, answer);
    }

    string getPermutation(int n, int k) {
        set<int> index;
        for (int i = 1; i <= n; i++) {
            index.insert(i);
        }
        string answer;
        func(n, k, index, answer);
        return answer;
    }
};
