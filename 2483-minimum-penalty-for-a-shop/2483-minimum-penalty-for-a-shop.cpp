class Solution {
public:
    int bestClosingTime(string c) {
        int y = count(c.begin(), c.end(), 'Y');
        int mint = 0;
        int minp = y;
        for(int i=0; i<c.size(); i++){
            c[i] == 'Y' ? y-- : y++;
            if(minp > y){
                minp = y;
                mint = i+1;
            }
        }
        return mint;
    }
};