class dsu{
    vector<int> parent;
public:
    dsu(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void reset(int node){
        parent[node] = node;
    }

    void unionbr(int v, int u){
        int pv = findPar(v);
        int pu = findPar(u);
        if(pv == pu)return;
        if(pv == 0)parent[pu] = 0;
        else if(pu == 0)parent[pv] = 0;
        else parent[u] = pv;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        dsu ds(n);
        ds.unionbr(0,firstPerson);
        int m = meetings.size();
        for(int i=0; i<m;){
            vector<int> temp;
            int time = meetings[i][2];
            while(i<m && meetings[i][2] == time){
                int p1 = meetings[i][0];
                int p2 = meetings[i][1];
                ds.unionbr(p1,p2);
                temp.push_back(p1);
                temp.push_back(p2);
                i++;
            }
            for(auto & num : temp){
                if(ds.findPar(num) != 0){
                    ds.reset(num);
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(ds.findPar(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     typedef pair<int,int> p;
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         unordered_map<int, vector<p>> adj;
//         for(auto& vec : meetings){
//             int p1 = vec[0];
//             int p2 = vec[1];
//             int t = vec[2];
//             adj[p1].emplace_back(p2,t);
//             adj[p2].emplace_back(p1,t);
//         }

//         priority_queue<p, vector<p>, greater<p>> pq;
//         vector<bool> vis(n,false); 
//         pq.push({0,0});
//         pq.push({0,firstPerson});

//         while(!pq.empty()){
//             auto [time,person] = pq.top();
//             pq.pop();
//             if(vis[person])continue;
//             vis[person] = true;

//             for(auto& nbr : adj[person]){
//                 int per = nbr.first;
//                 int t = nbr.second;
//                 if(t >= time && !vis[per]){
//                     pq.push({t,per});
//                 }
//             }
//         }
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             if(vis[i])ans.push_back(i);
//         }
//         return ans;
//     }
// };