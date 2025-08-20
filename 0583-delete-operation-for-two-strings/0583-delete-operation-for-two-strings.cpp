class Solution {
public:
    int find(int ind1, int ind2, string& word1, string& word2,vector<vector<int>>& dp){
        if(ind1 == 0){
            return ind2;
        }
        if(ind2 == 0){
            return ind1;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(word1[ind1-1] == word2[ind2-1]){
            return dp[ind1][ind2] = find(ind1-1,ind2-1,word1,word2,dp);
        }
        else{
            return dp[ind1][ind2] = 1 + min(find(ind1-1,ind2,word1,word2,dp),find(ind1,ind2-1,word1,word2,dp));
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> curr(n2+1,0);
        vector<int> prev(n2+1,0);
        for(int i=0; i<=n2; i++){
            prev[i] = i;
        }
        
        for(int ind1=1; ind1<=n1; ind1++){
            curr[0] = ind1;
            for(int ind2=1; ind2<=n2; ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    curr[ind2] = prev[ind2-1];
                }
                else{
                    curr[ind2] = 1 + min(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr;
        }
        return prev[n2];
        //return find(n1,n2,word1,word2,dp);
    }
};