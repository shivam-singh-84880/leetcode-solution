class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt=1;
        int l1=0;
        int l2=0;
        int ans=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                cnt++;
                ans = max(ans,cnt/2);
            }
            else{
                if(l1==0){
                    l1 = cnt;
                    cnt = 1;
                }
                else if(l2==0){
                    l2=cnt;
                    cnt=1;
                }
                else{
                    ans = max(ans,min(l1,l2));
                    l1 = l2;
                    l2 = cnt;
                    cnt = 1;
                }
            }
        }
        if(l2==0){
            l2 = cnt;
        }
        else if(cnt >= l2){
            l1 = l2;
            l2 = cnt;
        }
        else if(cnt > l1){
            l1 = cnt;
        }
        
        return max(ans,min(l1,l2));
    }
};