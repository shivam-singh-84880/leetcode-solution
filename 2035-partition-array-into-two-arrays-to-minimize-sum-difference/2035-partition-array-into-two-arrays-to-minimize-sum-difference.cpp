class Solution {
public:
    // int find(vector<int>& nums,int ind, int cnt,int sum, vector<vector<unordered_map<int,int>>> mp){
    //     if(cnt==0) return abs(sum);
    //     if(ind<0) return INT_MAX;
    //     if(mp[ind][cnt].count(sum)) return mp[ind][cnt][sum];
    //     return mp[ind][cnt][sum] = min(find(nums,ind-1,cnt-1,sum-2*nums[ind],mp),find(nums,ind-1,cnt,sum,mp));
        
    // }
    // int minimumDifference(vector<int>& nums) {
    //     int sum=0;
    //     int n = nums.size();
    //     for(auto x:nums) sum+=x;
    //     vector<vector<unordered_map<int,int>>> mp(n,vector<unordered_map<int,int>>(n/2+1));
    //     return find(nums,n-1,n/2,sum,mp);
    // }

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        int total = 0;
        for(int i=0; i<N; i++){
            total += nums[i];
        }
        vector<vector<int>> left(n+1);
        vector<vector<int>> right(n+1);

        for(int ss=0; ss<(1<<n); ss++){
            int sz=0;
            int ls=0;
            int rs=0;
            for(int i=0; i<n; i++){
                if(ss&(1<<i)){
                    sz++;
                    ls += nums[i];
                    rs += nums[n+i];
                }
            }
            left[sz].push_back(ls);
            right[sz].push_back(rs);
        }

        for(int i=0; i<=n; i++){
            sort(right[i].begin(),right[i].end());
        }

        int res = min(abs(total - 2*right[n][0]), abs(total - 2*left[n][0]));

        for(int sz=1; sz<n; sz++){
            for(auto l : left[sz]){
                int r = (total - 2*l)/2;
                int rsz = n - sz;
                auto itr = lower_bound(right[rsz].begin(),right[rsz].end(),r);
                if(itr != right[rsz].end()) res = min(res,abs(total - 2*(l+(*itr))));
                if(itr != right[rsz].begin()){
                    --itr;
                    res = min(res,abs(total - 2*(l+(*itr))));
                }
            }
        }
        return res;
    }
};