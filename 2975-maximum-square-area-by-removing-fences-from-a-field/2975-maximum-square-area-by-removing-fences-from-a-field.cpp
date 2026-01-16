class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> st;
        int len=-1;
        int mod = 1e9+7;

        for(int i=0; i<hFences.size(); i++){
            int h1 = hFences[i];
            for(int j=i+1; j<hFences.size(); j++){
                st.insert(hFences[j] - h1);
            } 
        }

        for(int i=0; i<vFences.size(); i++){
            int h1 = vFences[i];
            for(int j=i+1; j<vFences.size(); j++){
                if(st.find(vFences[j] - h1) != st.end()){
                    len = max(len,vFences[j] - h1);
                }
            } 
        }

        if(len == -1)return -1;
        else return (1ll*len*len)%mod;

    }
};