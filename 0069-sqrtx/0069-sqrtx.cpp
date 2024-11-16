class Solution {
public:
    int mySqrt(int x) {
         ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        if(x<2) return x;
        long l=0,r=x-1,ans=0;
        while(l<=r)
        {
            long m=l+(r-l)/2;

            if(m*m==x)
            {
                return m;
            }
            else if(m*m<x)
            {
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
            return ans;        
    }
};
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    Solution s;
    for (string line; getline(cin, line); cout << endl)    
            cout << s.mySqrt(stoul(line));    
    exit(0);
    return 0;
}();