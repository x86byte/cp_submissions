class LRUCache {
    unordered_map<int, int>m;
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        int  v= m[key];
        m[key] = -1;
        return v;
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
};
