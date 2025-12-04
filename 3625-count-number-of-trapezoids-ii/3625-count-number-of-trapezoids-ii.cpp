class Solution {
public:
    struct PairHash{
        size_t operator()(const pair<int,int>& p) const {
            long long val = ((long long)p.first << 32) ^ (long long)p.second;
            return hash<long long>()(val);
        }
    };
    int countTrapezoids(vector<vector<int>>& p) {
        unordered_map<float,vector<float>> ypnt;
        unordered_map<int,vector<float>> mid;
        for(int i=0; i<p.size(); i++){
            int x1 = p[i][0];
            int y1 = p[i][1]; 

            for(int j=i+1; j<p.size(); j++){
                int x2 = p[j][0];
                int y2 = p[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                float ypt;
                float slope;
                // pair<int,int> m = {x1+x2,y1+y2};

                int midkey = (x1+x2)*10000 + (y1+y2); // to create unique key

                if(dx != 0){
                    slope = (float)dy/dx;
                    ypt = (float)(y1*dx - dy*x1)/dx;
                }
                else{
                    slope = 1e9+7;
                    ypt = x1;
                }
                ypnt[slope].push_back(ypt);
                mid[midkey].push_back(slope);
            }
        }

        int ans=0;
        for(auto& [ypt,vec] : ypnt){
            unordered_map<float,int> mp;

            for(auto& val : vec){
                mp[val]++;
            }
            int hl=0;
            for(auto& [ypt,cnt] : mp){
                ans += cnt*hl;
                hl += cnt;
            }
        }

        for(auto& [ypt,vec] : mid){
            unordered_map<float,int> mp;

            for(auto& val : vec){
                mp[val]++;
            }
            int hl=0;
            for(auto& [ypt,cnt] : mp){
                ans -= cnt*hl;
                hl += cnt;
            }
        }

        return ans;
    }
};

