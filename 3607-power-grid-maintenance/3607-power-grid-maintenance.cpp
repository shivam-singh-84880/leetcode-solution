class dsu{
    vector<int> par;
    vector<int> rank;
public:
    dsu(int n){
        par.resize(n+1);
        rank.resize(n+1,1);
        iota(par.begin(),par.end(),0);
    }

    int findPar(int node){
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }

    void ubr(int u, int v){
        int rpu = findPar(u);
        int rpv = findPar(v);

        if(rpu == rpv) return;
        if(rank[rpu] < rank[rpv]) swap(rpu,rpv);
        par[rpv] = rpu;
        rank[rpu] += rank[rpv];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<set<int>> mp(c+1);
        vector<int> ans;
        dsu* d = new dsu(c);
        for(auto& it : connections){
            d->ubr(it[0],it[1]);
        }
        for(int i=1; i<=c; i++){
            mp[d->findPar(i)].insert(i);
        }

        for(auto& q : queries){
            int onof = q[0];
            int x = q[1];
            auto& st = mp[d->findPar(x)];
            if(onof == 2){
                st.erase(x);
            }
            else{
                if(st.empty()) ans.push_back(-1);
                else if(st.count(x)) ans.push_back(x);
                else ans.push_back(*st.begin());
            }
        }
        return ans;
    }
};