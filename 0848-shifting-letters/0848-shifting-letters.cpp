class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        long long sum = 0;
        for(int i=n-1; i>=0; i--){
            s[i] = 'a' + (s[i]-'a' + (sum + shifts[i])%26)%26;
            sum += shifts[i];
        }
        return s;
    }
};