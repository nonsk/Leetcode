class Solution {
public:
    int solve(int day, vector<int>& days, vector<int>& costs, vector<int>& dp, unordered_set<int>& travelDays) {
        cout<<day<<endl;
        if (day > days[days.size()-1]) {
            return 0;
        }
        if (dp[day] != -1) {
            return dp[day];
        }
        if (travelDays.find(day) == travelDays.end()) {
            return dp[day] = solve(day + 1, days, costs, dp, travelDays);
        }
        int ans = min({
            solve(day + 1, days, costs, dp, travelDays) + costs[0],
            solve(day + 7, days, costs, dp, travelDays) + costs[1],
            solve(day + 30, days, costs, dp, travelDays) + costs[2]
        });
        dp[day] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        unordered_set<int> travelDays(days.begin(), days.end());
        return solve(0, days, costs, dp, travelDays);
    }
};
