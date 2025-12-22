class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n,true);
        bool flag = false;
        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n-1; j++){
                if(sorted[j] && strs[j][i] > strs[j+1][i]){
                    res++;
                    flag = true;
                    break;
                }
            }
            if(flag){
                flag = false;
                continue;
            }
            for(int j=0; j<n-1; j++){
                sorted[j] = sorted[j] && strs[j][i] == strs[j+1][i];
            }
        }
        return res;   
    }
};