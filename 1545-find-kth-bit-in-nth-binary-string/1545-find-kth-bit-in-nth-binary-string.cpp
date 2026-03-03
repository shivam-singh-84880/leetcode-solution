class Solution {
public:
    string invert(string s){
        string temp="";
        for(char ch : s){
            if(ch=='0') temp += '1';
            else temp += '0'; 
        }
        return temp;
    }
    char findKthBit(int n, int k) {
        string ans = "0";
        if(n==1) return '0';
        while(ans.length()<k && --n>0){
            string temp = invert(ans);
            reverse(temp.begin(),temp.end());
            ans = ans + "1" + temp;
        }
        return ans[k-1];
    }
};