class Solution {
public:
    void getprime(int n, vector<int>& prime){
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                prime.push_back(i);
                if(n/i != i){
                    prime.push_back(n/i);
                }
            }
        }
    }

    void find(int ind, int k, int& n, vector<int>& prime, long long prod, vector<int>& ans, int& mini, vector<int>& res){
        if(ind < 0)return;
        
        if(k == 0){
            if(!ans.empty() && prod == n){
                int min_ = *min_element(ans.begin(),ans.end());
                int max_ = *max_element(ans.begin(),ans.end());
                cout<< max_ - min_ << " ";
                if(mini > max_ - min_){
                    mini = max_ - min_;
                    res = ans;
                }
            }
            return;
        }

        if(prod*prime[ind] <= n){
            ans.push_back(prime[ind]);
            find(ind,k-1,n,prime,prod*prime[ind],ans,mini,res);
            ans.pop_back();
        } 

        find(ind-1,k,n,prime,prod,ans,mini,res);
        return;
    }

    vector<int> minDifference(int n, int k) {
        vector<int> prime;
        getprime(n,prime);
        int ind = prime.size();
        vector<int> ans;
        int mini = INT_MAX;
        vector<int> res;
        find(ind-1, k, n, prime, 1, ans,mini,res);
        return res;
    }
};