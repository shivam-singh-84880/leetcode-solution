class Solution {
public:
    typedef pair<long long, int> p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<p, vector<p>, greater<p>> use;
        priority_queue<int, vector<int>, greater<int>> available;
        vector<int> check(n,0);
        for(int i=0; i<n; i++){
            available.push(i);
        }

        for(auto & meet : meetings){
            int s = meet[0];
            int e = meet[1];
            int d = e - s;

            while(!use.empty() && use.top().first <= s){
                available.push(use.top().second);
                use.pop();
            }
            if(!available.empty()){
                int r = available.top();
                check[r]++;
                use.push({e,r});
                available.pop();
            }
            else{
                int r = use.top().second;
                long long t = use.top().first;
                check[r]++;
                use.pop();
                use.push({t+d,r});
            }
        }

        int ans=0;
        int ind=-1;
        for(int i=0; i<n; i++){
            if(check[i] > ans){
                ind = i;
                ans = check[i];
            }
        }
        return ind;
    }
};