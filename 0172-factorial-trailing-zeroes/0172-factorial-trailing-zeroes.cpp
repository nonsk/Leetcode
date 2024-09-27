class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int k = 1;
        while ((n / (int)pow(5, k))!=0) {
            count = count + n / (int)pow(5, k);
            k++;
        }
        return count;
    }
};