class Solution {
public:
    int integerBreak(int n) {
        int count = 1;
        if(n==3){
            return 2;
        }
        int i=1;
        int rem;
        int max = 1;
        while(i<(n+1)/2){
            rem = n - i*(n/i);
            count = (int)pow(n/i,i - rem)*pow(n/i+1,rem);
            if(max<count){
                max = count;
            }
            i++;
        }
        return max;
    }
};