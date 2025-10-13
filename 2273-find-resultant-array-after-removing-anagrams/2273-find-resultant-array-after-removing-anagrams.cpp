class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        vector<int> freq(26,0);
        for(int i=0; i<words[0].size(); i++){
            freq[words[0][i]-'a']++;
        }
        ans.push_back(words[0]);
        int j=1;
        int n = words.size();
        while(j<n){
            vector<int> temp(26,0);
            for(int i=0; i<words[j].size(); i++){
                temp[words[j][i]-'a']++;
            }
            for(int i=0; i<26; i++){
                if(freq[i] != temp[i]){
                    ans.push_back(words[j]);
                    freq = temp;
                    break;
                }
            }
            j++;
        }
        return ans;
    }
};