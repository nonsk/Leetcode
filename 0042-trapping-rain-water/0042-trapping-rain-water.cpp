class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lmax = l;
        int rmax = r;
        int n = height.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);

        for (int i = 0; i < n; i++) {

            if (height[i] > height[lmax]) {
                lmax = i;
            }
            leftmax[i] = height[lmax];
        }

        for (int i = n-1; i >= 0; i--) {

            if (height[i] > height[rmax]) {
                rmax = i;
            }
            rightmax[i] = height[rmax];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = min(leftmax[i], rightmax[i]);
        }
        int blac = 0;
        int blac_blue = 0;
        for (int i = 0; i <n; i++) {
            blac_blue += ans[i];
            blac += height[i];
        }

        for (int i = 0; i <n; i++) {
            cout<<ans[i]<<" ";
        }

        return blac_blue - blac;
    }
};