class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    Solution s;
    for (string line; getline(cin, line); cout << endl)    
            cout << s.mySqrt(stoul(line));    
    exit(0);
    return 0;
}();