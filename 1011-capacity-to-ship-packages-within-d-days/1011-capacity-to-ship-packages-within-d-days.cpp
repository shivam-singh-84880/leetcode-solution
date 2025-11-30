class Solution {
public:
    int check(int mwt, vector<int>& weights, int days, int& n){
        int sum=0;
        days--;
        for(int i=0; i<n; i++){
            if(weights[i] > mwt)return false;
            sum += weights[i];
            if(sum > mwt){
                days--;
                sum = weights[i];
                if(days < 0)return false;
            }
            
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s=0;
        int e = accumulate(weights.begin(), weights.end(),0);

        while(s <= e){
            int mid = (s+e)/2;
            if(check(mid,weights,days,n)){
                e = mid-1;
            }
            else s = mid+1;
        }
        return s;
    }
};