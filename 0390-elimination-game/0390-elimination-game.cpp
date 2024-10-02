class Solution {
public:
    int lastRemaining(int n) {
        long long k=n,count=0,flag=1;
        while(n-1){
           if((n%2==1 && flag==1) || (flag==0)){
               k=k-pow(2,count);
           }
            n=n/2;
            count++;
            if(flag==1){
                flag=0;
            }
            else if(flag==0){
                flag=1;
            }
        }
        return k;
    }
};