class Solution {
public:
    int find(vector<int>& dp){
        int n = dp.size();
        stack<int> st;
        int ele = 0;
        int ans=0;
        int height = 0;
        int right = 0;
        int left = 0;
        for(int i=0; i<=n; i++){
            ele = (i==n) ? 0 : dp[i];
            while(!st.empty() && dp[st.top()] >= ele){
                height = dp[st.top()];
                st.pop();
                right = i;
                left = !st.empty() ? st.top() : -1;
                ans = max(ans, height * (right - left - 1));
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m,0);
        int area = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    dp[j] = 0;
                }
                else{
                    dp[j]++;
                }
            }
            area = find(dp);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};