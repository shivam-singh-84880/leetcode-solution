class Solution {
public:
    bool isValidCode(string str){
        if(str.empty()) return false;
        for(char ch : str){
            if(!isalnum(ch) && ch != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int> checkBl{{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
        vector<pair<int,string>> res;
        vector<string> ans;
        for(int i=0; i<code.size(); i++){
            if(isActive[i] && isValidCode(code[i]) && checkBl.count(businessLine[i])){
                res.emplace_back(checkBl[businessLine[i]],code[i]);
            }
        }
        sort(res.begin(), res.end(), [](auto& a, auto& b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        for(auto& it : res){
            ans.push_back(it.second);
        }
        return ans;
    }
};