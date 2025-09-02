
class Solution {
  public:
    void find(vector<int>& ans, stack<int>& st){
        if(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            find(ans,st);
        }
        return;
    }
    void find2(vector<int>& ans, stack<int>& st,int ind){
        if(ind < ans.size()){
            st.push(ans[ind]);
            ind++;
            find2(ans,st,ind);
        }
        return;
    }
    
    void reverse(stack<int> &st) {
        // code here
        vector<int> ans;
        find(ans,st);
        find2(ans,st,0);
    }
};