class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        int temp=0;
        while(num2 > 0){
            cnt += num1/num2;
            temp = num1%num2;
            num1 = num2;
            num2 = temp;
        }
        return cnt;
    }
};