class Node{
public:
    Node* next[2];
    Node(){
        next[0] = NULL;
        next[1] = NULL;
    }
    void insert(int num, Node*& root){
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1; 
            if(!temp->next[bit]){
                Node* tnode = new Node();
                temp->next[bit]  = tnode;
            }
            temp = temp->next[bit];
        }
    }

    int xormax(int num, Node*& root){
        int resxor = 0;
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1; 
            if(temp->next[1-bit]){
                resxor |= (1<<i);
                temp = temp->next[1-bit];
            }
            else{
                temp = temp->next[bit];
            }
        }
        return resxor;
    }

};
class Solution {
    Node* root;
public:
    Solution(){
        root = new Node();
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, pair<int,int>>> qr;
        int nq = queries.size();
        for(int i=0; i<nq; i++){
            int m = queries[i][1];
            int x = queries[i][0];
            qr.push_back({m,{x,i}});
        }
        sort(qr.begin(),qr.end());
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans(nq,-1);  
        int j = 0;
        for(int i=0; i<nq; i++){
            int m = qr[i].first;
            int x = qr[i].second.first;
            int ind = qr[i].second.second;
            while(j < n){
                if(nums[j] <= m){
                    root->insert(nums[j],root);
                    j++;
                }
                else{
                    break;
                }
            }
            if(j != 0){
                ans[ind] = root->xormax(x,root);
            }
        }
        return ans;
    }
};