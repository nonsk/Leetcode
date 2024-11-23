const unordered_set<string> st {
            "1", "3", "9", "27", "81", "243", "729", "2187", "6561", "19683", "59049", "177147", "531441", "1594323", "4782969", "14348907", "43046721", "129140163", "387420489", "1162261467"
        };
class Solution {
public:
    bool isPowerOfThree(int n) {
        return false;
    }
};

auto init = ([]() -> char {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ofstream out("user.out");
    string s;
    auto stEnd = st.end();
    out << boolalpha;
    while(getline(cin, s)) {
        out << (st.find(s) != stEnd) << '\n';
    }
    out.flush();
    exit(0);
    return 1;
})();