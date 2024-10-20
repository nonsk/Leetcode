class Solution {
public:
    bool isUgly(int n) {
        if (n == 1) {
            return true;
        }
                if (n == 0) {
            return false;
        }
        while(n%2==0){
            cout<<n<<endl;
            n = n/2;
        }
        while(n%3==0){
            cout<<n<<endl;
            n = n/3;
        }
        while(n%5==0){
            cout<<n<<endl;
            n = n/5;
        }
        cout<<n;
        if(n==1){
            return true;
        }
        return false;
    }
};