class Solution {
public:
    bool ispossible(int sum, int ind, int & k, vector<int>& temp){
        if(sum == k)return true;
        if(ind >= temp.size())return false;
        
        if(ispossible(sum + temp[ind], ind+1, k, temp))return true;
        if(ispossible(sum, ind+1, k, temp)) return true;
        
        return false;
        
    }
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> temp;
        for(int x=1; x<=n; x++){
            for(int i=0; i<n; i++){
                temp.push_back(min(x,nums[i]));
            }
            if(ispossible(0,0,k,temp)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            temp = {};
        }
        return ans;
    }
};