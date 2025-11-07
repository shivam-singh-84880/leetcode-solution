class Solution {
public:
    bool check(long long maxp, int k, int& r, vector<long long>& pw, int& n){
        vector<long> range(n,0);
        long curr=0;
        for(int i=0; i<n; i++){
            if(i>0) range[i] += range[i-1];
            curr = pw[i] + range[i];
            if(curr < maxp){
                long need = maxp - curr;
                if(need > k) return false;
                k -= need;
                range[i] += need;
                int rg = min(n-1,i + 2*r);
                if(rg+1 < n) range[rg+1] -= need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long ans = 0;
        vector<long long> pw(n,0);
        for(int i=0; i<n; i++){
            int l = max(0,i-r);
            int re = min(n-1,i+r);
            pw[l] += stations[i];
            if(re+1 < n){
                pw[re+1] -= stations[i];
            } 
        }
        long long mini = pw[0];
        for(int i=1; i<n; i++){
            pw[i] += pw[i-1];
            mini = min(mini,pw[i]);
        }
        long l=0;
        long rh=mini+k;

        while(l <= rh){
            long long mid = l + (rh-l)/2;
            if(check(mid,k,r,pw,n)){
                ans = mid;
                l = mid+1;
            }
            else rh = mid - 1;
        }
        return ans;
    }
};