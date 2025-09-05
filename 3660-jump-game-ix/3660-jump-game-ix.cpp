class dsu{
    vector<int> par;
    vector<int> sz;
public:
    dsu(int n){
        sz.resize(n,1);
        par.resize(n,0);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int u){
        if(par[u] == u)return u;
        return par[u] = find(par[u]);
    }

    void unions(int u, int v){
        int upu = find(u);
        int upv = find(v);

        if(upu == upv) return;
        if(sz[upu] >= sz[upv]){
            par[upv] = upu;
            sz[upu] += sz[upv];
        }
        else{
            par[upu] = upv;
            sz[upv] += sz[upu];
        }
    }
};
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        dsu d(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            int g = i;
            while(!st.empty() && nums[st.top()] > nums[i]){
                if(nums[st.top()] > nums[g]) g = st.top();
                d.unions(st.top(),i);
                st.pop();
            }
            st.push(g);
        }

        vector<int> maxi(n, 0);
        for(int i = 0; i < n; i++){
            int p = d.find(i);
            maxi[p] = max(maxi[p], nums[i]);
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = maxi[d.find(i)];
        }
        return ans;

        
        
        // int n = nums.size();
        // vector<int> maxi(n,0);
        // vector<int> mini(n,0);
        // vector<int> ans(n,0);
        // maxi[0] = nums[0];
        // mini[n-1] = nums[n-1];
        // for(int i=1; i<n; i++){
        //     maxi[i] = max(maxi[i-1],nums[i]);
        //     mini[n-i-1] = min(mini[n-i],nums[n-i-1]);
        // }
        // ans[n-1] = maxi[n-1];
        // for(int i=n-2; i>=0; i--){
        //     if(maxi[i] > mini[i+1]){
        //         ans[i] = ans[i+1];
        //     }
        //     else{
        //         ans[i] = maxi[i];
        //     }
        // }
        // return ans;
    }
};