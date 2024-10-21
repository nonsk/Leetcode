class Solution {
public:
    void sort(int& ax1, int& ay1, int& ax2, int& ay2) {
        if (ax1 > ax2) {
            swap(ax1, ax2);
        }
        if (ay1 > ay2) {
            swap(ay1, ay2);
        }
    }
    int area(int ax1, int ay1, int ax2, int ay2) {
        int length = ax2 - ax1;
        int breadth = ay2 - ay1;
        return length * breadth;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        // sort(ax1, ay1, ax2, ay2);
        // sort(bx1, by1, bx2, by2);
        int totalArea = area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2);
        int overlapX1 = max(ax1, bx1); 
        int overlapY1 = max(ay1, by1); 
        int overlapX2 = min(ax2, bx2); 
        int overlapY2 = min(ay2, by2);
        int overlapArea = 0;
        if (overlapX1 < overlapX2 && overlapY1 < overlapY2) {
            overlapArea = area(overlapX1, overlapY1, overlapX2, overlapY2);
        }
        return totalArea - overlapArea;
    }
};