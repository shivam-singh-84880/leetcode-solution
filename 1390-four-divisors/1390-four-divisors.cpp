class Solution {
public:
    int check(int num){
        int sum=0;
        int d=0;
        for(int i=1; i*i<=num; i++){
            if(num%i == 0){
                int q = num/i;
                if(i == q){
                    sum += i;
                    d += 1;
                }
                else{
                    d += 2;
                    sum += i + q;
                }
            }
            if(d > 4)return 0;
        }
        if(d == 4)return sum;
        else return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto num : nums){
            ans += check(num);
        }
        return ans;
    }
};