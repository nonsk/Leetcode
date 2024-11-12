class Solution {
public:
    int nthUglyNumber(int n) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        set<ll> st;
        q.push(1);
        st.insert(1);
        ll ugly = 1;
        for (int i = 1; i <= n; ++i) {
            ugly = q.top();
            q.pop();
            if (st.insert(ugly * 2).second) q.push(ugly * 2);
            if (st.insert(ugly * 3).second) q.push(ugly * 3);
            if (st.insert(ugly * 5).second) q.push(ugly * 5);
        }
        return static_cast<int>(ugly);
    }
};
