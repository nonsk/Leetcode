class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int a = (x>y)?y:x;
        int b = (x>y)?x:y;
        if(x+y<target){
            return false;
        }
        if(target%a==0){
            return true;
        }
        else if(target%gcd(a,b)==0){
            return true;
        }
        return false;
    }
};