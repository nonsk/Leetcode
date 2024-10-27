class LRUCache {
public:
    int capacity;
    list<pair<int, int>> ll; // Doubly linked list to store keys and values
    unordered_map<int, list<pair<int, int>>::iterator> cache; // Map to store key and iterator to the list

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // Check if key exists in cache
        if (cache.find(key) != cache.end()) {
            // Move accessed key to the end (most recently used)
            ll.splice(ll.end(), ll, cache[key]);
            return cache[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // Check if key already exists
        if (cache.find(key) != cache.end()) {
            // Update the value and move it to the end
            cache[key]->second = value;
            ll.splice(ll.end(), ll, cache[key]);
        } else {
            // If capacity is full, remove the least recently used item
            if (ll.size() == capacity) {
                // Remove from both list and map
                cache.erase(ll.front().first);
                ll.pop_front();
            }
            // Insert new key-value pair at the end
            ll.push_back({key, value});
            cache[key] = --ll.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
