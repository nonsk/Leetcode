class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if (valid.find(endGene) == valid.end()) {
            return -1;
        }

        vector<char> genes = {'A', 'C', 'G', 'T'};
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while (!q.empty()) {
            auto [currentGene, mutations] = q.front();
            q.pop();

            if (currentGene == endGene) {
                return mutations;
            }

            for (int i = 0; i < currentGene.size(); ++i) {
                char original = currentGene[i];
                for (char gene : genes) {
                    if (gene != original) {
                        currentGene[i] = gene;
                        if (valid.find(currentGene) != valid.end() &&
                            visited.find(currentGene) == visited.end()) {
                            q.push({currentGene, mutations + 1});
                            visited.insert(currentGene);
                        }
                    }
                }
                currentGene[i] = original;
            }
        }

        return -1;
    }
};
