class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        if(a[1] < b[1]) return true;
        else if(a[1] == b[1]){
            return a[0] > b[0];
        }
        else return false;
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int ans=0;
        int p1 = -1;
        int p2 = -1;
        for(auto it : intervals){
            int l = it[0];
            int r = it[1];
            if(p2 < l){
                ans += 2;
                p2 = r;
                p1 = r-1;
            }
            else if(p1 < l){
                ans += 1;
                p1 = p2;
                p2 = r;
            }
        }
        return ans;
    }
};