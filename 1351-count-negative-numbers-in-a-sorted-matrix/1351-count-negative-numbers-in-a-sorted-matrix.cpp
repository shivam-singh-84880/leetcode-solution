class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans=0;
        int i=n-1;
        int j=0;

        while(i >= 0 && j < m){
            if(grid[i][j] < 0){
                ans += m - j;
                i--;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};