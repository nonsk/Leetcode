class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
   // Adjust k for the missing elements before the first element in the array
    k = k - (arr[0] - 1);
    
    if (k <= 0) {
        // If k <= 0, it means the k-th missing element is before the first element in the array
        return arr[0] + k - 1;  // Equivalent to returning (1 + (k - 1))
    }

    // Iterate over the array to adjust k between elements
    for (int i = 1; i < arr.size(); i++) {
        k = k - (arr[i] - arr[i - 1] - 1);
        
        if (k <= 0) {
            return arr[i] + k - 1;
        }
    }

    // If k is still positive, the missing element is beyond the last element in the array
    return arr[arr.size() - 1] + k;
}

};