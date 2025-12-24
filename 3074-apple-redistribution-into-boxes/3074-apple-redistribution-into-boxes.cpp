class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        vector<int> pre(51,0);
        int h=INT_MIN;
        int l=INT_MAX;
        int sum = accumulate(apple.begin(), apple.end(),0);
        for(auto &num : capacity){
            pre[num]++;
            h = max(h,num);
            l = min(l,num);
        }
        int res=0;
        for(int i=h; i>=l; i--){
            while(pre[i] > 0 && sum > 0){
                sum -= i;
                pre[i]--;
                res++;
            }
        }
        return res;
    }
};