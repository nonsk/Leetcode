class Solution {
public:
    vector<int> constructRectangle(int area) {
        int y = sqrt(area);
        while(area % y != 0) {
            y--;
        }
        return (y > area / y) ? vector<int>{y, area / y} : vector<int>{area / y, y};
    }
};
