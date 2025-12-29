class Solution {
public:
    unordered_map<string, bool> dp;
    bool find(int ind, string bottom, string up, unordered_map<string,vector<char>>& mp){
        if(bottom.size() == 1)return true;
        string key = bottom + "_" + to_string(ind) + "_" + up;
        if(dp.count(key))return dp[key];
        if(ind == bottom.size()-1){
            return dp[key] = find(0,up,"",mp);
        }

        string curr = bottom.substr(ind,2);

        for(auto& ch : mp[curr]){
            up.push_back(ch);
            if(find(ind+1,bottom,up,mp)) return true;
            up.pop_back();
        }
        return dp[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> mp;
        for(auto & str : allowed){
            mp[str.substr(0,2)].push_back(str[2]);
        }
        return find(0,bottom,"",mp);
    }
};