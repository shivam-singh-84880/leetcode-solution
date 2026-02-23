class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string>st;
        int total = 1<<k;
        for(int i=k;i<=n;i++){
            string sub = s.substr(i-k,k);
            if(!st.count(sub)){
                st.insert(sub);
                total--;
            }
            if(total==0){
                return true;
            }
        }
        return false;
    }
};