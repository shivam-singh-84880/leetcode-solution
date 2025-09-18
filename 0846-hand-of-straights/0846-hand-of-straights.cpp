class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>, greater<int>> pq;
        unordered_map<int,int> mp;
        int n = hand.size();
        if(n%groupSize != 0)return false;
        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }
        for(auto &it:mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(mp[val] > 0){
                int cnt = mp[val];
                for(int i=0; i<groupSize; i++){
                    if(mp[val+i]>0){
                        if(mp[val+i] < cnt)return false;
                        mp[val+i] -= cnt;
                    }
                    else{
                        return false;
                    }
                }
            }
            // if(mp[val] > 0){
            //     pq.push(val);
            // }
        }
        return true;
    }

};