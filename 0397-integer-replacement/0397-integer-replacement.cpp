class Solution {
public:
    int solve(long long n, std::unordered_map<long long, int>& memo) {
        if (n == 1) return 0;
        if (memo.count(n)) return memo[n];

        if (n % 2 == 0) {
            memo[n] = 1 + solve(n / 2, memo);
        } else {
            memo[n] = 1 + std::min(solve(n + 1, memo), solve(n - 1, memo));
        }

        return memo[n];
    }

    int integerReplacement(int n) {
        std::unordered_map<long long, int> memo;
        return solve(n, memo);
    }
};
