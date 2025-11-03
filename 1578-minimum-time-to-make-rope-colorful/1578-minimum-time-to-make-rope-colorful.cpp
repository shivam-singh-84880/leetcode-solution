class Solution {
public:

    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans=0;
        int i=1;
        while(i<n){
            if(colors[i-1] != colors[i]){
                i++;
            }
            else{
                int sum = neededTime[i-1];
                int maxi = neededTime[i-1];
                while(colors[i-1] == colors[i]){
                    maxi = max(maxi,neededTime[i]);
                    sum += neededTime[i];
                    i++;
                }
                ans += sum - maxi;
            }
        }
        return ans;
    }
};