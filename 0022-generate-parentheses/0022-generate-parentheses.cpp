class Solution {
public:
    vector<string> ans;
    void find(int op, int cl, int& n, string s){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(op < n) find(op+1,cl,n,s+'(');
        if(cl < op) find(op,cl+1,n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        find(0,0,n,s);
        return ans;
    }
};