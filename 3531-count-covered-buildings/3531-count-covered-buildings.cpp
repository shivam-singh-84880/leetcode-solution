class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> mpx;
        unordered_map<int,pair<int,int>> mpy;
        int ans=0;

        for(auto& it : buildings){
            int x = it[0];
            int y = it[1];

            if(!mpx.count(x)) mpx[x] = {INT_MAX,INT_MIN};
            if(!mpy.count(y)) mpy[y] = {INT_MAX,INT_MIN};

            mpx[x].first = min(mpx[x].first,y);
            mpx[x].second = max(mpx[x].second,y);
            mpy[y].first = min(mpy[y].first, x);
            mpy[y].second = max(mpy[y].second, x);
        }

        for(auto& it : buildings){
            int x = it[0];
            int y = it[1];
            if(mpx[x].first < y && y < mpx[x].second && mpy[y].first < x && x < mpy[y].second){
                ans++;
            }
        }
        return ans;
    }
};