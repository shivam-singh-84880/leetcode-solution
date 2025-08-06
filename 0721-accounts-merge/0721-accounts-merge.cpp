class dsu{
    vector<int> parent;
    vector<int> size;
public:
    dsu(int n){
        size.resize(n,0);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int fndpar(int node){
        if(parent[node] == node) return node;
        return parent[node] = fndpar(parent[node]);
    }

    void unions(int v, int u){
        int rpu = fndpar(u);
        int rpv = fndpar(v);

        if(rpu == rpv) return;

        if(size[rpu] < size[rpv]){
            parent[rpu] = rpv;
            size[rpv] += size[rpu];
        }
        else{
            parent[rpv] = rpu;
            size[rpu] += size[rpv];
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu ds(n);
        unordered_map<string,int> mp;
        // make union
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unions(i,mp[mail]);
                }
            }
        }
        //arrange in order
        vector<vector<string>> arrg(n);
        for(const auto &[mail,node] : mp){
            int p = ds.fndpar(mp[mail]);
            arrg[p].push_back(mail);
        }
        //insert in ans
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            vector<string>temp;
            if(arrg[i].size() == 0) continue;
            else{
                temp.push_back(accounts[i][0]);
                for(auto mail : arrg[i]){
                    temp.push_back(mail);
                }
            }
            sort(temp.begin()+1,temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};