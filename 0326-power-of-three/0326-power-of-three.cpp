class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double temp= 1;
        while(temp<=n){
            if(temp==n){
                return true;
            }
            temp *= 3;
        }
        return false;
    }
};