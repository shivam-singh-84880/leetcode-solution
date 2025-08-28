class Solution {
public:
    int find(int ind1, int ind2, string& word1, string& word2, vector<vector<int>>& dp){
        if(ind2 == 0)return ind1;
        if(ind1 == 0)return ind2;
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(word1[ind1-1] == word2[ind2-1]){
            return dp[ind1][ind2] = find(ind1-1,ind2-1,word1,word2,dp);
        }
        else{
            return dp[ind1][ind2] = 1 + min(find(ind1,ind2-1,word1,word2,dp),min(find(ind1-1,ind2,word1,word2,dp),find(ind1-1,ind2-1,word1,word2,dp)));
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return find(n1,n2,word1,word2,dp);
    }
};