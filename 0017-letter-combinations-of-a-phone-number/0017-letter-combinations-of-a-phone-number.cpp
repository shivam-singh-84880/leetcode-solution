class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void find(int i, int& n, string& s, string& digits){
        if(i == n){
            ans.push_back(s);
            return;
        }
        for(char ch : mp[digits[i]]){
            s.push_back(ch);
            find(i+1,n,s,digits);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return ans;
        int n = digits.size();
        string s = "";
        find(0,n,s,digits);
        return ans;
    }
};