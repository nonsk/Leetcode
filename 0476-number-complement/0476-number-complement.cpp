class Solution {
public:
    int b2n(int num){
        int ans = 0;
        int i =0;
        while(num!=0){
            ans += num%2*(int)pow(2,i);
            num/=10;
            i++;
        }
        return ans;
    }
     int comp(int num) {
        int count = 0;
        long long i = 1;
        while (num != 0) {
            int bit = num % 2;
            bit = (bit) ? 0 : 1;
            count += bit * i;
            i *= 10;
            num /= 2;
        }
        return count;
    }
    int findComplement(int num) {
        return b2n(comp(num));
    }
};