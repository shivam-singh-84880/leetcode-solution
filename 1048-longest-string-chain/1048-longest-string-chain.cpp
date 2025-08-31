class Solution {
public:
    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
    
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    static bool comp(const string& s1, const string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 0;
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(compare(words[i],words[j])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
};