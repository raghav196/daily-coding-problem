class LRUCache {
public:
    int size;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    void moveToFront(int key, int val) {
        dll.erase(hash[key]);
        dll.push_front(make_pair(key, val));
        hash[key] = dll.begin();
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        } else { // key found
            int val = hash[key]->second;
            moveToFront(key, val); // move the key to the front
            return hash[key]->second;
        }
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) { // key already in the cache
            moveToFront(key, value);
        } else { // key not present
            // insert the (key, val) pair
            dll.push_front(make_pair(key, value));
            hash[key] = dll.begin();
            
            if (hash.size() > this->size) {
                // delete from back
                hash.erase(dll.back().first); // delete the last key from the list
                dll.pop_back();
                
            }
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
