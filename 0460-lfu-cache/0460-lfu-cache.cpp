class LFUCache {
    unordered_map<int,pair<int,int>> keyfreq;
    unordered_map<int, list<int>> freqkeylist;
    unordered_map<int, list<int>::iterator> keyaddr;
    int sz;
    int minfreq;

    void updatekeyfreq(int key){
        int freq = keyfreq[key].second;
        freqkeylist[freq].erase(keyaddr[key]);

        if(freqkeylist[freq].size() == 0){
            freqkeylist.erase(freq);
            if(freq == minfreq)minfreq++;
        }
        keyfreq[key].second++;
        freqkeylist[freq+1].push_front(key);
        keyaddr[key] = freqkeylist[freq+1].begin();
    }

public:
   LFUCache(int capacity) {
        sz = capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(keyfreq.find(key) != keyfreq.end()){
            int val = keyfreq[key].first;
            updatekeyfreq(key);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(sz <= 0)return;
        if(keyfreq.find(key) != keyfreq.end()){
            keyfreq[key].first = value;
            updatekeyfreq(key);
            return;
        }
        else{
            if(keyfreq.size() >= sz){
                int _key = freqkeylist[minfreq].back();
                keyaddr.erase(_key);
                keyfreq.erase(_key);
                freqkeylist[minfreq].pop_back();
            }
            keyfreq[key] = {value,0};
            freqkeylist[0].push_front(key);
            keyaddr[key] = freqkeylist[0].begin();
            minfreq = 0;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */