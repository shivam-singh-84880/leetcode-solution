class Node{
public:
    Node* next[2];
    Node(){
        next[0] = NULL;
        next[1] = NULL;
    }
};
class Solution {
    Node* root;
public:
    Solution(){
        root = new Node();
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

    int findMaximumXOR(vector<int>& nums) {
        for(auto num : nums){
            insert(num,root);
        }

        int maxi = 0;
        for(auto num : nums){
            int ans = xormax(num,root);
            maxi = max(ans,maxi);
        }
        return maxi;
    }
};