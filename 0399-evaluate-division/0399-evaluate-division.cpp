class Solution {
public:
    double traverse(string start, string end,
                    unordered_map<string, vector<pair<string, double>>>& mp,
                    unordered_map<string, bool>& vis) {
        cout << start << " " << end << endl;
        vis[start] = true;
        if (start == end) {
            return 1;
        }
        for (auto it : mp[start]) {
            if (vis[it.first] == true) {
                continue;
            }
            double prod = traverse(it.first, end, mp, vis);
            if (prod != -1) {
                return it.second * prod;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for (int i = 0; i < equations.size(); i++) {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        // for (auto it : mp) {
        //     cout << it.first << " : ";
        //     for (auto it2 : it.second) {
        //         cout << it2.first << "," << it2.second << endl;
        //     }
        // }
        vector<double> ans;
        for (auto it : queries) {
            unordered_map<string, bool> vis;
            string start = it[0];
            string end = it[1];
            if (mp.find(start) == mp.end() || mp.find(end) == mp.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(traverse(start, end, mp, vis));
            }
        }
        return ans;
    }
};