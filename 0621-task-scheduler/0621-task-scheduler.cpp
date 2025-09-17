class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int sz = tasks.size();
        for(int i=0; i<sz; i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int fill = (freq[0]-1)*n;
        for(int i=1; i<26; i++){
            if(freq[i] > 0){
                fill = fill - min(freq[i],freq[0]-1);
            }
        }
        return sz+max(0,fill);
    }
};