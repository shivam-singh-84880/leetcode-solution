class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int c=1; c<=n; c++){
            int i=1;
            int j=c-1;
            int t = c*c;
            int sum=0;
            while(i < j){
                sum = i*i + j*j;
                if(sum == t){
                    ans += 2;
                    i++;
                    j--;
                }
                else if(sum < t){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return ans;
    }
};