class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int up = 0;
        int down = 0;
        int sum = 1;

        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            up = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                up++;
                sum += up;
                i++;
            }
            down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down++;
            }
            if(down > up){
                sum += down - up;
            }
        }
        return sum;
    }
};