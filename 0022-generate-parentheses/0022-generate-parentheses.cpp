class Solution {
public:
        void solve(string str, int k, int c, vector<string> &ans, int n){
            if(c>k||c>n){
                cout<<str<<endl;
                return;
            }
            if(c==n){
                cout<<str<<endl;
                //store
                ans.push_back(str);
                return;
            }
            cout<<str<<endl;
            if(k<n){solve(str+'(', k+1, c, ans,n);}
            if(c<n){solve(str+')', k, c+1, ans,n);}

            return;


        }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("(", 1, 0, ans, n);
        return ans;
    }
};