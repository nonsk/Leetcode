class RandomizedSet {
public:
unordered_set <int> yo; 
    RandomizedSet() {yo.clear(); }

    bool insert(int val) {
        int size_set = yo.size();
        yo.insert(val);
        return (yo.size() == size_set) ? false : true;
    }

    bool remove(int val) {
        int size_set = yo.size();
        yo.erase(val);
        return (yo.size() == size_set) ? false : true;
    }

    int getRandom() {
        int size_set = yo.size();
        int num = rand() % (size_set);
        auto it = next(yo.begin(), num);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */