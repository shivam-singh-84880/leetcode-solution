class Solution {
public:
    int find(vector<pair<int,int>> mp, int& k, int& x){
        int sum=0;
        sort(mp.begin(),mp.end(),greater<pair<int,int>>());
        for(int i=0; i<x; i++){
            auto [f,ele] = mp[i];
            if(f == 0)break;
            sum += f*ele;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<pair<int,int>> mp(51);
        vector<int> ans;

        for(int i=0; i<k; i++){
            mp[nums[i]].first++;
            mp[nums[i]].second = nums[i];
        }

        ans.push_back(find(mp,k,x));

        for(int i=k; i<nums.size(); i++){
            mp[nums[i-k]].first--;
            mp[nums[i]].first++;
            mp[nums[i]].second = nums[i];
            ans.push_back(find(mp,k,x));
        }

        return ans;
    }
};