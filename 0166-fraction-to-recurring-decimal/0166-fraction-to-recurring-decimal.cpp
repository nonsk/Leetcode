class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        long long n1 = static_cast<long long>(numerator);
        long long q;
        long long mul;
        long long rem;
        int limit = 0;

        if (n1 == 0)
            return "0";

        if ((n1 < 0) ^ (denominator < 0))
            ans += "-";
        n1 = abs(n1);
        denominator = abs(denominator);

        q = n1 / denominator;
        rem = n1 % denominator;
        ans += to_string(q);
        if (rem == 0)
            return ans;

        ans += ".";
        unordered_map<long long, int> mp;
        string last = "";

        while (rem != 0 && limit < 100) {
            if (mp.find(rem) != mp.end()) {

                ans.insert(mp[rem], "(");
                ans += ")";
                return ans;
            }

            mp[rem] = ans.size();

            rem *= 10;
            q = rem / denominator;
            ans += to_string(q);
            rem = rem % denominator;

            limit++;
        }

        return ans;
    }
};
