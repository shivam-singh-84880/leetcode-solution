class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int as=0;
        int n = bottomLeft.size();

        for(int i=0; i<n; i++){
            int s,xtmin,xbmax,ytmin,ybmax=0;
            for(int j=i+1; j<n; j++){
                xtmin = min(topRight[i][0],topRight[j][0]);
                xbmax = max(bottomLeft[i][0],bottomLeft[j][0]);

                ytmin = min(topRight[i][1],topRight[j][1]);
                ybmax = max(bottomLeft[i][1],bottomLeft[j][1]);

                s = min(xtmin - xbmax, ytmin - ybmax);
                as = max(as,s);
            }
        }

        return 1ll*as*as;
    }
};