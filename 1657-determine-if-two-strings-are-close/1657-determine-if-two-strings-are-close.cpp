class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // map<char, int> alpha;
        set <char> alpha;
        vector<int> num(26, 0);
        for (auto it : word1) {
            alpha.insert(it);
            num[it-'a']++;
        }
        // for (auto it : alpha) {
        //     num.push_back(it.second);
        // }
        // map<char, int> alpha2;
        set <char> alpha2;
        vector<int> num2(26,0);
        for (auto it : word2) {
            alpha2.insert(it);
            num2[it-'a']++;
        }
        // for (auto it : alpha2) {
        //     num2.push_back(it.second);
        // }
        sort(num.begin(), num.end());
        sort(num2.begin(), num2.end());
        bool flag1 = true;
        bool flag2 = true;
        // for(auto it: alpha){
        //     if(alpha2.find(it.first)==alpha2.end()){
        //         flag1 = false;
        //     }
        // }
        if(alpha != alpha2){
            flag1 = false;
        }
        
        if (num != num2) {
            flag2 = false;
        }
        return flag1&flag2;
    }
};