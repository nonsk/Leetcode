class Solution {
public:
    int MOD = 1e9+7;

    void nsi(const vector<int>& arr, vector<int>& ns) {
        int n = arr.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void psi(const vector<int>& arr, vector<int>& ps) {
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ns(n), ps(n);
        nsi(arr, ns);
        psi(arr, ps);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left_count = i - ps[i];
            long long right_count = ns[i] - i;
            long long contribution = (left_count * right_count % MOD * arr[i] % MOD) % MOD;
            ans = (ans + contribution) % MOD;
        }
        return ans;
    }
};
