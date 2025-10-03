class Solution {
public:
    vector<vector<string>> ans;
    bool pal(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void find(int ind, int& n, string& s, vector<string>& temp){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<n; i++){
            if(pal(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                find(i+1,n,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        int n = s.size();
        find(0,n,s,temp);
        return ans;
    }
};