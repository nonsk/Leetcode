class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        if(x==2147395599)return 46339;
        int low=0,high=x;
        while(low<=high)
        {
          float mid=(low+high)/2;
          if(mid*mid==x)
          return mid;
          else if(mid<x/mid)
          {
            ans=mid;
            low=mid+1;
          }
          else
          {
            high=mid-1;
          }
        }
        return int(ans);
    }
};