class Solution {
public:
    bool find(int ind, string& s, unordered_set<string>& st){
        if(ind == s.size()){
            return true;
        }

        for(int i=ind; i<s.size(); i++){
            if(st.find(s.substr(ind,i-ind+1)) != st.end()){
                if(find(i+1,s,st))return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }

        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[n] = true;

        for(int j=n-1; j>=0; j--){
            for(int i=j; i<n; i++){
                if(st.find(s.substr(j,i-j+1)) != st.end()){
                    if(dp[i+1]){
                        dp[j] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[0];
    }
};