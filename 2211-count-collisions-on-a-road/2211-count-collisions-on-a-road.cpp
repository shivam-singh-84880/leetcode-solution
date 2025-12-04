class Solution {
public:
    int countCollisions(string d) {
        int ans=0;
        int n=d.size();
        int l=0, r=n-1;
        while( l<r && d[l] == 'L')l++;
        while( l<r && d[r] == 'R')r--;
        if(l >= r)return 0;
        while(l <= r){
            ans += d[l] != 'S';
            l++;
        }
        return ans;
    }
};