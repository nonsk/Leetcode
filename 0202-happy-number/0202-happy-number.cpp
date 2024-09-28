class Solution {
public:
    int sum_return (int n){
        int ans=0;
        while(n!=0){
            ans = ans+(n%10)*(n%10);
            n = n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        cout<<sum_return(19);
        unordered_set <int> umap;
        int str = n;
        while(str!=1){
            if(umap.find(str)!=umap.end()){
                return false;
            }
            umap.insert(str);
            str = sum_return(str);
        }
        return true;
    }
};