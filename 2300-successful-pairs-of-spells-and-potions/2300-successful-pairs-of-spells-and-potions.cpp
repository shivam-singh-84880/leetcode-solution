class Solution {
public:
    int binary(vector<int>& potions, long long ele, int i, int j, long long& success){
        if(i > j)return i;
        int mid = (i+j)/2;
        if(ele*potions[mid] >= success){
            j = mid-1;
        }
        else{
            i = mid+1;
        }
        return binary(potions,ele,i,j,success);
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++){
            int ind = m - binary(potions,spells[i],0,m-1,success);
            ans.push_back(ind);
        }
        return ans;
    }
};

