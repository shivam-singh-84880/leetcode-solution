class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> lind(26,-1);
        vector<int> rind(26,-1);
        int res=0;

        for(int i=0; i<n; i++){
            int ind = s[i] - 'a';
            if(lind[ind] == -1){
                lind[ind] = i;
            }
            rind[ind] = i;
        }

        for(int i=0; i<26; i++){
            int li = lind[i];
            int ri = rind[i];

            if(li == -1 || ri == -1)continue;
            unordered_set<int> st;
            for(int j=li+1; j<ri; j++){
                st.insert(s[j]);
            }
            res += st.size();
        }

        return res;
    }
};