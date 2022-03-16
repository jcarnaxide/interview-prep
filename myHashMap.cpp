class MyHashMap {
public:   
    void put(int key, int value) {
        int original_key = key;
        key %= memory.size();
        list<pair<int, int>>::iterator iter = find_if(memory[key].begin(), memory[key].end(), [&](pair<int, int>& p){ return p.first == original_key; });
        if(iter != memory[key].end()){
            iter->second = value;
        }
        else{
            memory[key].push_back(make_pair(original_key, value));
        }
    }
    
    int get(int key) {
        int original_key = key;
        key %= memory.size();
        list<pair<int, int>>::iterator iter = find_if(memory[key].begin(), memory[key].end(), [&](pair<int, int>& p){ return p.first == original_key; });
        if(iter != memory[key].end()){
            return iter->second;
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        int original_key = key;
        key %= memory.size();
        memory[key].remove_if([&](pair<int, int>& p){ return p.first == original_key; });
    }
private:
    vector<list<pair<int, int>>> memory{10000, list<pair<int, int>>{}};
};
