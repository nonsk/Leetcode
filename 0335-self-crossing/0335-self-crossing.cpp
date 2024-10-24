class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int x = 0;
        int y = 0;
        int dir = 0;

        for (int i = 3; i < distance.size(); i++) {
            cout<<i<<endl;
            if (i == 4 && distance[3] == distance[1] &&
                distance[4] >= (distance[2] - distance[0])) {
                return true;
            }
            if (i <= 4) {
                if (distance[i - 1] <= distance[i - 3] &&
                    distance[i] >= distance[i - 2]) {
                    return true;
                }
                continue;
            }
            if (distance[i - 1] <= distance[i - 3]) {
                if (distance[i - 3] - distance[i - 5] >= 0 &&
                    distance[i - 1] >= distance[i - 3] - distance[i - 5]) {
                    if (distance[i - 2] - distance[i - 4]>0&&distance[i] >= distance[i - 2] - distance[i - 4]) {
                        return true;
                    }
                } else {
                    if (distance[i - 2] - distance[i - 4]>=0 && distance[i] >= distance[i - 2] - distance[i - 4]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};