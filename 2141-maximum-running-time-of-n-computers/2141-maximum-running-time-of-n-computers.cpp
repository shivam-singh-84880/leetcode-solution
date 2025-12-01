class Solution {
public:
    long long check(vector<int>& batteries, long long need){
        long long p=0;
        for(auto& power : batteries){
            p += min(need, (long long)power);
        }
        return p;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans=0;
        long long s=1;
        long long e=accumulate(batteries.begin(),batteries.end(),0LL);

        while(s <= e){
            long long mid = (s+e)/2;
            if(check(batteries,mid) >= mid*n){
                s = mid+1;
            }
            else e = mid-1;
        }
        return e;
    }
};