class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;

        //// -1,1,-1
        vector<int> sols(n, 1);
        for (int i = 0; i < n; i++) {
            sols[i] = gas[i] - cost[i];
            sum = sum + sols[i];
        }
        int left = 0;
        if (sum < 0) {
            return -1;
        }
        // tank = 0;
        // for (int i = 0; i < n; i++) {
        //         cout << left<<endl;
        //         left = left + sols[i];

        //     if (left >= left-sum &&) {
        //         index = i;
        //     }
        // }
        int tank =0;
        int max_tank=INT_MIN;
        int index = -1;
        int diff=0;
        for (int i = n-1; i >= 0; i--) {

            diff += gas[i]-cost[i];
            if(diff>max_tank){
                max_tank = diff;
                index = i;
            }
        }
        return index;
    }
};