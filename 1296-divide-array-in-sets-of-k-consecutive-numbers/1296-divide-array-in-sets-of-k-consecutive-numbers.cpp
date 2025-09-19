class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        if(n%k != 0)return false;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        auto it = mp.begin();
        while(it!=mp.end()){
            int val = it->first;
            if(mp[val] > 0){
                for(int i=0; i<k; i++){
                    if(mp[val+i] > 0){
                        mp[val+i]--;
                    }
                    else return false;
                }
            }
            if(mp[val] == 0){
                it++;
            }
        }
        return true;
    }
};