class Solution {
public:
    bool find(int num, vector<int>& friends, int s, int e){
        int mid = 0;
        while(s <= e){
            mid = (s+e)/2;
            if(friends[mid] == num){
                return true;
            }
            else if(friends[mid] > num){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return false;
    }

    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int on = order.size();
        int fn = friends.size();
        vector<int> ans;
        for(int i=0; i<on; i++){
            int num = order[i];
            if(find(num,friends,0,fn-1)){
                ans.push_back(num);
            }
        }
        return ans;
    }
};