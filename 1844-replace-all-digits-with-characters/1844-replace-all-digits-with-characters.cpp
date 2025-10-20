class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i=1; i<n; i+=2){
            s[i] = 'a' + s[i-1]-'a' + s[i]-'0';
        }
        return s;
    }
};