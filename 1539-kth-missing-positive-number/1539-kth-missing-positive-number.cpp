class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = arr.size();
        vector<int> index(arr[x-1]+1, 1);
        for (int i = 0; i < x; i++) {
            index[arr[i]] = 0;
        }
        for (int i = 1; i < index.size(); i++) {
            if (index[i] == 1) {
                k--;
            }
            if (k==0) {
                return i;
            }
        }
        return index.size() - 1 + k;
    }
};