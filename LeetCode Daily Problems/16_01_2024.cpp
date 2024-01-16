class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> m;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            v.push_back(val);
            m[val] = v.size() - 1;

            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int newVal = v[v.size()-1];
            int newIndex = m[val];
            v[newIndex] = newVal;
            m[newVal] = newIndex;
            v.pop_back();
            m.erase(val);
            
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int r = rand()%v.size();
        return v[r];
    }
};

//TC: O(1);
//SC: O(n);


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */