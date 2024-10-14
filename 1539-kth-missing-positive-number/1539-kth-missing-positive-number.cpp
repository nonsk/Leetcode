class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> index(arr[arr.size() - 1]+1, 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
            index[arr[i]] = 0;
        }
        cout<<endl;
        for (auto it : index) {
            cout << it << " ";
        }
        int ans = 0;
        for (int i = 1; i < index.size(); i++) {
            if (index[i] == 1) {
                ans++;
            }
            if (ans == k) {
                cout<<"here"<<endl;
                return i;
            }
        }
        cout<<endl<<ans<<endl;
        return index.size() - 1 + k-ans;
    }
};