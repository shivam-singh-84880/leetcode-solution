class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre10(n,0);
        int res = 0;
        pre10[0] = s[0] == '1' ? 1 : 0;
        for(int i=1; i<n; i++){
            pre10[i] = pre10[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int onec = pre10[j] - (i-1 >= 0 ? pre10[i-1] : 0);
                int zc = (j-i+1) - onec;

                if((zc*zc) > onec){
                    j += (zc*zc) - onec;
                    j -= 1;
                }
                else if(zc*zc == onec){
                    res += 1;
                }
                else{
                    res += 1;
                    int k = sqrt(onec) - zc;
                    if(k + j < n){
                        res += k;
                    }
                    else {
                        res += n-j-1;
                        break;
                    }
                    j += k;
                }
            }
        }
        return res;
    }
};