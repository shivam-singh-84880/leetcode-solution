class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int,int>> L,R;
        unordered_map<int,int> cnt;
        vector<long long> ans;
        long long sum=0;

        auto addPair = [&](int val){
            int f = cnt[val];
            R.insert({f,val});
        };

        auto removePair = [&](int val){
            int f = cnt[val];
            pair<int,int> p = {f,val};
            auto it = L.find(p);
            if(it != L.end()){
                sum -= 1.0 * f*val;
                L.erase(it);
            }
            else{
                it = R.find(p);
                if(it != R.end()){
                    R.erase(it);
                }
            }
        };

        auto balance = [&](){
            while(L.size() < x && !R.empty()){
                auto it = prev(R.end());
                L.insert(*it);
                sum += 1.0 * it->first * it->second; 
                R.erase(it);
            }

            while(!L.empty() && !R.empty()){
                auto bestR = prev(R.end());
                auto worstL = L.begin();
                int fr = bestR->first;
                int fl = worstL->first;
                if(fr > fl || (fr == fl && bestR->second > worstL->second)){
                    sum -= 1.0 * fl * worstL->second;
                    sum += 1.0 * fr * bestR->second;
                    L.insert(*bestR);
                    R.insert(*worstL);
                    L.erase(*worstL);
                    R.erase(*bestR);
                }
                else break;
            }

        };

        for(int i=0; i<nums.size(); i++){
            int inE = nums[i];
            if(cnt.count(inE) > 0){
                removePair(inE);
            }
            cnt[inE]++;
            addPair(inE);

            if(i >= k){
                int outE = nums[i-k];
                removePair(outE);
                cnt[outE]--;
                if(cnt[outE] == 0) cnt.erase(outE);
                else addPair(outE);
            }

            balance();

            if(i-k+1 >= 0){
                ans.push_back(sum);
            }

        }

        return ans;
    }
};