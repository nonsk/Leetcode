class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> alpha;
        vector<int> num;
        for (auto it : word1) {
            alpha[it]++;
        }
        for (auto it : alpha) {
            num.push_back(it.second);
        }
        map<char, int> alpha2;
        vector<int> num2;
        for (auto it : word2) {
            alpha2[it]++;
        }
        for (auto it : alpha2) {
            num2.push_back(it.second);
        }
        sort(num.begin(), num.end());
        sort(num2.begin(), num2.end());
        bool flag1 = true;
        bool flag2 = true;
        for(auto it: alpha){
            if(alpha2.find(it.first)==alpha2.end()){
                flag1 = false;
            }
        }
        
        if (num != num2) {
            flag2 = false;
        }
        return flag1&flag2;
    }
};