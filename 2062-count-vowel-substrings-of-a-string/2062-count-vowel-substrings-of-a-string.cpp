class Solution {
public:
    int find(int trg, string& word){
        unordered_map<char,int> mp;
        int ans=0;
        int i=0;
        int n=word.size();
        for(int j=0; j<n; j++){
            if(word[j]!='a' && word[j]!='e' && word[j]!='i' && word[j]!='o' && word[j]!='u'){
                i = j+1;
                mp.clear();
                continue;
            }
            mp[word[j]]++;
            while(mp.size()>trg){
                mp[word[i]]--;
                if(mp[word[i]]==0){
                    mp.erase(word[i]);
                }
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int countVowelSubstrings(string word) {
        return find(5,word) - find(4,word);
    }
};