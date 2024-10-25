class SmallestInfiniteSet {
public:
    unordered_set<int> rej;
    int min1;
    SmallestInfiniteSet() { min1 = 1; }
    int popSmallest() {
        while(rej.find(min1)!=rej.end()){
            min1++;
        }
        rej.insert(min1);
        return min1;
    }
    void addBack(int num) {
        if (rej.find(num) != rej.end()) {
            rej.erase(num);
        }
        if (num < min1) {
            min1 = num;
        }
    }
};