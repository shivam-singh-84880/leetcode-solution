class Solution {
public:
    int dp[501][501];
    int find(int ind1, int ind2, vector<int>& nums1, vector<int>& nums2){
        if(ind1 < 0 || ind2 < 0)return -1e9;
        if(dp[ind1][ind2] != -1e9)return dp[ind1][ind2];
        int r1 = nums1[ind1]*nums2[ind2];
        int r2 = nums1[ind1]*nums2[ind2] + find(ind1-1, ind2-1, nums1, nums2);
        int r3 = find(ind1-1,ind2,nums1,nums2);
        int r4 = find(ind1,ind2-1,nums1,nums2);

        return dp[ind1][ind2] = max({r1,r2,r3,r4});

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0; i<501; i++){
            for(int j=0; j<501; j++){
                dp[i][j] = -1e9;
            }
        }
        return find(n1-1,n2-1,nums1,nums2);
    }
};