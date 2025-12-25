class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto &num : happiness){
            pq.push(num);
        }
        long long ans=0;
        int val=0;
        for(int i=0; i<k; i++){
            val = pq.top()-i;
            if(val <= 0)break;
            ans += max(val,0);
            pq.pop();
        }
        return ans;
    }
};