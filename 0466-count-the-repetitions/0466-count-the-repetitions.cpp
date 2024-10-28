class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1_len = s1.size(), s2_len = s2.size();
        int count1 = 0, count2 = 0;
        int index_s2 = 0;
        unordered_map<int, pair<int, int>> seen;

        while (count1 < n1) {
            for (int i = 0; i < s1_len; ++i) {
                if (s1[i] == s2[index_s2]) {
                    index_s2++;
                    if (index_s2 == s2_len) {
                        index_s2 = 0;
                        count2++;
                    }
                }
            }
            count1++;
            if (seen.find(index_s2) != seen.end()) {
                auto [prev_count1, prev_count2] = seen[index_s2];
                int cycle_len1 = count1 - prev_count1;
                int cycle_len2 = count2 - prev_count2;

                int cycles = (n1 - count1) / cycle_len1;
                count1 += cycles * cycle_len1;
                count2 += cycles * cycle_len2;
            }
            else {
                seen[index_s2] = {count1, count2};
            }
        }

        return count2 / n2;
    }
};
