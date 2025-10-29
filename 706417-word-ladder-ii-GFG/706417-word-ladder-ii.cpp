// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
        vector<string>& wordList) {
        
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()){
            int n = q.size();
            vector<string> visited;
            for(int i=0; i<n; i++){
                vector<string> temp = q.front();
                q.pop();
                string back = temp.back();
                if(back == endWord){
                    ans.push_back(temp);
                    continue;
                }
                for(int j=0; j<back.size(); j++){
                    char org = back[j];
                    for(char ch = 'a'; ch<='z'; ch++){
                        back[j] = ch;
                        if(st.count(back) > 0){
                            temp.push_back(back);
                            q.push(temp);
                            temp.pop_back();
                            visited.push_back(back);
                        }
                    }
                    back[j] = org;
                }
            }
            for(int i=0; i<visited.size(); i++){
                if(st.count(visited[i]) > 0){
                    st.erase(visited[i]);
                }
            }
        }
        return ans;
    }
};



